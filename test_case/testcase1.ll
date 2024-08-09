define i32 @cal() {
  %1 = alloca i32
  %2 = alloca i32
  %3 = alloca i32
  %4 = alloca i32
  %5 = alloca i32
  store i32 1, i32* %1
  store i32 3, i32* %2
  %6 = load i32, i32* %1
  %7 = load i32, i32* %2
  %8 = add i32 %6, %7
  store i32 %8, i32* %3
  %9 = load i32, i32* %1
  %10 = load i32, i32* %2
  %11 = mul i32 %9, %10
  store i32 %11, i32* %4
  %12 = load i32, i32* %3
  %13 = load i32, i32* %2
  %14 = sdiv i32 %12, %13
  store i32 %14, i32* %5
  %15 = load i32, i32* %5
  ret i32 %15
}
