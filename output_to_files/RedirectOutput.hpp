  #pragma once

  #include <gtest/gtest.h>
  
  class RedirectOutput : public testing::EmptyTestEventListener {
    // Called before a test starts.
    void OnTestStart(const testing::TestInfo& test_info) override;

    // Called after a test ends.
    void OnTestEnd(const testing::TestInfo& test_info) override;
  };