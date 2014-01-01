/*  shell
    Copyright 2014 Michael Gruber

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <readline/history.h>
#include <readline/readline.h>


#define AUTO_COMPLETE_KEY '\t'
#define ENVIRONMENT_VARIABLE_FOR_USER_NAME "USER"
#define EXIT_MESSAGE "\n"
#define MAX_CURRENT_WORKING_DIRECTORY_LENGTH 512
#define MAX_HOST_NAME_LENGTH 64
#define MAX_SHELL_PROMPT_LENGTH 512


char* get_user_name() {
  return getenv(ENVIRONMENT_VARIABLE_FOR_USER_NAME);
}


char* read_line() {
  char shell_prompt[MAX_SHELL_PROMPT_LENGTH];
  char host_name[MAX_HOST_NAME_LENGTH];
  char current_working_directory[MAX_CURRENT_WORKING_DIRECTORY_LENGTH];

  gethostname(host_name, MAX_HOST_NAME_LENGTH);
  getcwd(current_working_directory, MAX_CURRENT_WORKING_DIRECTORY_LENGTH);

  snprintf(shell_prompt, MAX_SHELL_PROMPT_LENGTH,
           "%s at %s in %s $ ", get_user_name(), host_name, current_working_directory);

  return readline(shell_prompt);
}


int main() {

  char* input_line;
  bool requested_exit = false;

  rl_bind_key(AUTO_COMPLETE_KEY, rl_complete);

  while(!requested_exit) {
    input_line = read_line();
 
    if (!input_line) {
      requested_exit = true;
    } else {
      system(input_line); 
      add_history(input_line);
    }

    free(input_line);
  }

  printf(EXIT_MESSAGE);
  return EXIT_SUCCESS;
}
