#include "Keyboard_Handle.h"



Keyboard_Handle::Keyboard_Handle(const std::chrono::milliseconds& timeOut):
m_timeOut(timeOut)
{
  m_promiseObj = promise<char>();
}

future<char> Keyboard_Handle::get_future_value()
{
  set_promise();
  future<char> f = m_promiseObj.get_future();
  return f;
}

void Keyboard_Handle::set_promise()
{
  promise<char> promiseObj;
  m_promiseObj = std::move(promiseObj);
}

void Keyboard_Handle::operator()()
{
  while(true)
  {
    int ch = getch();
    m_buffer_key.push(ch);
  }
}

bool Keyboard_Handle::keypress(int& ch, bool& isSet)
{
  std::chrono::time_point<std::chrono::steady_clock>  start = std::chrono::steady_clock::now();
  std::chrono::milliseconds duration(m_timeOut); // Set the duration for the loop to run (5 seconds in this example)

  while(std::chrono::steady_clock::now() - start < duration)
  {
    if(m_buffer_key.size() != 0)
    {
      ch = m_buffer_key.front();
      m_buffer_key.pop();
      isSet = true;
      break;
    }
  }

  return false;
}
