#include <iostream>

class IntContainer {
protected:
  int int_value;
  int int_value2;
};

class IntContainerWithFunction {
protected:
  int int_value;
  int int_value2;
public:
  int value() {
    return int_value;
  }
};

class IntContainerWithVirtualFunction {
protected:
  int int_value;
  int int_value2;
public:
  virtual int value() {
    return int_value;
  }
  virtual ~IntContainerWithVirtualFunction(){
  }
};

class InheritIntContainerWithFunction : public IntContainerWithFunction {
};

class InheritIntContainerWithVirtualFunction : public IntContainerWithVirtualFunction {
public:
  virtual int value2() {
    return int_value2;
  }
};

size_t print_size(const char* const label, size_t size) {
  std::cout << label << " : " << size << std::endl;
  return size;
}

int main(void) {
  print_size("int", sizeof(int));
  print_size("int*", sizeof(int*));
  print_size("IntContainer", sizeof(IntContainer));
  print_size("IntContainerWithFunction", sizeof(IntContainerWithFunction));
  print_size("IntContainerWithVirtualFunction", sizeof(IntContainerWithVirtualFunction));
  print_size("InheritIntContainerWithVirtualFunction", sizeof(InheritIntContainerWithVirtualFunction));
  return sizeof(IntContainer)
    + sizeof(IntContainerWithFunction)
    + sizeof(IntContainerWithVirtualFunction)
    + sizeof(InheritIntContainerWithVirtualFunction);
}
