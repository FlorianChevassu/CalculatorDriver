add_executable(CalculatorDriverTestExecutable CalculatorDriverTest.cpp)

# Add tests that should work
add_test(NAME CalculatorDriverTest_Add COMMAND CalculatorDriverTestExecutable SUCCESS $<TARGET_FILE:CalculatorDriver> 1 + 2)
add_test(NAME CalculatorDriverTest_Substract COMMAND CalculatorDriverTestExecutable SUCCESS $<TARGET_FILE:CalculatorDriver> 18 - 20)

# Add tests that should fail
add_test(NAME CalculatorDriverTest_Multiply_Fail COMMAND CalculatorDriverTestExecutable ERROR $<TARGET_FILE:CalculatorDriver> 1 * 2)
add_test(NAME CalculatorDriverTest_Divide_Fail COMMAND CalculatorDriverTestExecutable ERROR $<TARGET_FILE:CalculatorDriver> 18 / 6)
add_test(NAME CalculatorDriverTest_Parameter_Order_Fail COMMAND CalculatorDriverTestExecutable ERROR $<TARGET_FILE:CalculatorDriver> + 1 2)
add_test(NAME CalculatorDriverTest_Parameter_Number_Fail COMMAND CalculatorDriverTestExecutable ERROR $<TARGET_FILE:CalculatorDriver> 1 2)