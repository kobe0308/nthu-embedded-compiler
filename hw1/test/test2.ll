; ModuleID = 'test2.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %i = alloca i32, align 4
  %A = alloca [60 x i32], align 16
  %C = alloca [60 x i32], align 16
  %D = alloca [60 x i32], align 16
  store i32 0, i32* %1, align 4
  store i32 2, i32* %i, align 4
  br label %2

; <label>:2                                       ; preds = %22, %0
  %3 = load i32, i32* %i, align 4
  %4 = icmp slt i32 %3, 20
  br i1 %4, label %5, label %25

; <label>:5                                       ; preds = %2
  %6 = load i32, i32* %i, align 4
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [60 x i32], [60 x i32]* %C, i64 0, i64 %7
  %9 = load i32, i32* %8, align 4
  %10 = load i32, i32* %i, align 4
  %11 = sext i32 %10 to i64
  %12 = getelementptr inbounds [60 x i32], [60 x i32]* %A, i64 0, i64 %11
  store i32 %9, i32* %12, align 4
  %13 = load i32, i32* %i, align 4
  %14 = mul nsw i32 3, %13
  %15 = sub nsw i32 %14, 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [60 x i32], [60 x i32]* %A, i64 0, i64 %16
  %18 = load i32, i32* %17, align 4
  %19 = load i32, i32* %i, align 4
  %20 = sext i32 %19 to i64
  %21 = getelementptr inbounds [60 x i32], [60 x i32]* %D, i64 0, i64 %20
  store i32 %18, i32* %21, align 4
  br label %22

; <label>:22                                      ; preds = %5
  %23 = load i32, i32* %i, align 4
  %24 = add nsw i32 %23, 1
  store i32 %24, i32* %i, align 4
  br label %2

; <label>:25                                      ; preds = %2
  ret i32 0
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"}
