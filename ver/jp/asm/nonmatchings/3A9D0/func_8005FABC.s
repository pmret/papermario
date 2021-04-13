.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FABC
/* 3AEBC 8005FABC 0000282D */  daddu     $a1, $zero, $zero
/* 3AEC0 8005FAC0 24060004 */  addiu     $a2, $zero, 4
/* 3AEC4 8005FAC4 3C03800B */  lui       $v1, %hi(D_800B1D27)
/* 3AEC8 8005FAC8 24631D27 */  addiu     $v1, $v1, %lo(D_800B1D27)
/* 3AECC 8005FACC 00A0202D */  daddu     $a0, $a1, $zero
.L8005FAD0:
/* 3AED0 8005FAD0 3C01800B */  lui       $at, %hi(D_800B1D26)
/* 3AED4 8005FAD4 00240821 */  addu      $at, $at, $a0
/* 3AED8 8005FAD8 A0261D26 */  sb        $a2, %lo(D_800B1D26)($at)
/* 3AEDC 8005FADC 2484000A */  addiu     $a0, $a0, 0xa
/* 3AEE0 8005FAE0 90620000 */  lbu       $v0, ($v1)
/* 3AEE4 8005FAE4 24A50001 */  addiu     $a1, $a1, 1
/* 3AEE8 8005FAE8 34420080 */  ori       $v0, $v0, 0x80
/* 3AEEC 8005FAEC A0620000 */  sb        $v0, ($v1)
/* 3AEF0 8005FAF0 2CA20004 */  sltiu     $v0, $a1, 4
/* 3AEF4 8005FAF4 1440FFF6 */  bnez      $v0, .L8005FAD0
/* 3AEF8 8005FAF8 2463000A */   addiu    $v1, $v1, 0xa
/* 3AEFC 8005FAFC 03E00008 */  jr        $ra
/* 3AF00 8005FB00 0000102D */   daddu    $v0, $zero, $zero
