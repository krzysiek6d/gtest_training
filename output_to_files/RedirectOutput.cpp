#include "RedirectOutput.hpp"
#include <stdio.h>
#include <gtest/gtest.h>
#include <unistd.h>

namespace
{
static int fd;
static fpos_t pos;

void switchStdout(const char *newStream)
{
  fflush(stdout);
  fgetpos(stdout, &pos);
  fd = dup(fileno(stdout));
  freopen(newStream, "w", stdout);
}

void revertStdout()
{
  fflush(stdout);
  dup2(fd, fileno(stdout));
  close(fd);
  clearerr(stdout);
  fsetpos(stdout, &pos);
}
}

// Called before a test starts.
void RedirectOutput::OnTestStart(const testing::TestInfo& test_info) {
    printf("*** Test %s.%s starting.\n",
            test_info.test_suite_name(), test_info.name());
    std::string filename = std::string(test_info.test_suite_name()) + "_" + std::string(test_info.name());
    switchStdout(filename.c_str());
}

// Called after a test ends.
void RedirectOutput::OnTestEnd(const testing::TestInfo& test_info) {
    revertStdout();
    printf("*** Test %s.%s ending.\n",
            test_info.test_suite_name(), test_info.name());
}
