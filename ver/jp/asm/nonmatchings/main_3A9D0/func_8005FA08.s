.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FA08
/* 3AE08 8005FA08 8C84000C */  lw        $a0, 0xc($a0)
/* 3AE0C 8005FA0C 90830000 */  lbu       $v1, ($a0)
/* 3AE10 8005FA10 8C850008 */  lw        $a1, 8($a0)
/* 3AE14 8005FA14 00031080 */  sll       $v0, $v1, 2
/* 3AE18 8005FA18 00431021 */  addu      $v0, $v0, $v1
/* 3AE1C 8005FA1C 90A30006 */  lbu       $v1, 6($a1)
/* 3AE20 8005FA20 00021040 */  sll       $v0, $v0, 1
/* 3AE24 8005FA24 3C01800B */  lui       $at, %hi(D_800B1D26)
/* 3AE28 8005FA28 00220821 */  addu      $at, $at, $v0
/* 3AE2C 8005FA2C A0231D26 */  sb        $v1, %lo(D_800B1D26)($at)
/* 3AE30 8005FA30 90830000 */  lbu       $v1, ($a0)
/* 3AE34 8005FA34 00031080 */  sll       $v0, $v1, 2
/* 3AE38 8005FA38 00431021 */  addu      $v0, $v0, $v1
/* 3AE3C 8005FA3C 94A30002 */  lhu       $v1, 2($a1)
/* 3AE40 8005FA40 00021040 */  sll       $v0, $v0, 1
/* 3AE44 8005FA44 3C01800B */  lui       $at, %hi(D_800B1D22)
/* 3AE48 8005FA48 00220821 */  addu      $at, $at, $v0
/* 3AE4C 8005FA4C A4231D22 */  sh        $v1, %lo(D_800B1D22)($at)
/* 3AE50 8005FA50 90830000 */  lbu       $v1, ($a0)
/* 3AE54 8005FA54 00031080 */  sll       $v0, $v1, 2
/* 3AE58 8005FA58 00431021 */  addu      $v0, $v0, $v1
/* 3AE5C 8005FA5C 94A30000 */  lhu       $v1, ($a1)
/* 3AE60 8005FA60 00021040 */  sll       $v0, $v0, 1
/* 3AE64 8005FA64 3C01800B */  lui       $at, %hi(D_800B1D20)
/* 3AE68 8005FA68 00220821 */  addu      $at, $at, $v0
/* 3AE6C 8005FA6C A4231D20 */  sh        $v1, %lo(D_800B1D20)($at)
/* 3AE70 8005FA70 90830000 */  lbu       $v1, ($a0)
/* 3AE74 8005FA74 00031080 */  sll       $v0, $v1, 2
/* 3AE78 8005FA78 00431021 */  addu      $v0, $v0, $v1
/* 3AE7C 8005FA7C 00021040 */  sll       $v0, $v0, 1
/* 3AE80 8005FA80 3C01800B */  lui       $at, %hi(D_800B1D24)
/* 3AE84 8005FA84 00220821 */  addu      $at, $at, $v0
/* 3AE88 8005FA88 A4201D24 */  sh        $zero, %lo(D_800B1D24)($at)
/* 3AE8C 8005FA8C 03E00008 */  jr        $ra
/* 3AE90 8005FA90 0000102D */   daddu    $v0, $zero, $zero
