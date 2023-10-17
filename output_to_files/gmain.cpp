#include <gtest/gtest.h>
#include "RedirectOutput.hpp"

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  // Gets hold of the event listener list.
  testing::TestEventListeners& listeners =
      testing::UnitTest::GetInstance()->listeners();
  // Adds a listener to the end.  GoogleTest takes the ownership.
  listeners.Append(new RedirectOutput);
  return RUN_ALL_TESTS();
}