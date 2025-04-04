if(input)
  if(input-file)
    message(FATAL_ERROR "Both input and input-file")
  endif()
  execute_process(
    COMMAND ${CMAKE_ARGV0} -E echo ${input}
    COMMAND ${command}
    OUTPUT_FILE ${output-file}
    RESULTS_VARIABLE results
    ERROR_VARIABLE error)
elseif(input-file)
  execute_process(
    COMMAND ${CMAKE_ARGV0} -E cat ${input-file}
    COMMAND ${command}
    OUTPUT_FILE ${output-file}
    RESULTS_VARIABLE results
    ERROR_VARIABLE error)
else()
  execute_process(
    COMMAND ${command}
    OUTPUT_FILE ${output-file}
    RESULTS_VARIABLE results
    ERROR_VARIABLE error)
endif()
foreach(result IN LISTS results)
  if(result)
    message(FATAL_ERROR "${command}: ${error}")
  endif ()
endforeach()
