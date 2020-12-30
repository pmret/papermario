.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B60_6BC6F0
/* 6BC6F0 80218B60 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6BC6F4 80218B64 AFB00018 */  sw        $s0, 0x18($sp)
/* 6BC6F8 80218B68 0080802D */  daddu     $s0, $a0, $zero
/* 6BC6FC 80218B6C 3C0542D4 */  lui       $a1, 0x42d4
/* 6BC700 80218B70 3C064310 */  lui       $a2, 0x4310
/* 6BC704 80218B74 0000202D */  daddu     $a0, $zero, $zero
/* 6BC708 80218B78 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6BC70C 80218B7C AFB1001C */  sw        $s1, 0x1c($sp)
/* 6BC710 80218B80 8E11000C */  lw        $s1, 0xc($s0)
/* 6BC714 80218B84 3C013F80 */  lui       $at, 0x3f80
/* 6BC718 80218B88 44810000 */  mtc1      $at, $f0
/* 6BC71C 80218B8C 0000382D */  daddu     $a3, $zero, $zero
/* 6BC720 80218B90 AFA00014 */  sw        $zero, 0x14($sp)
/* 6BC724 80218B94 0C01C844 */  jal       func_80072110
/* 6BC728 80218B98 E7A00010 */   swc1     $f0, 0x10($sp)
/* 6BC72C 80218B9C 0200202D */  daddu     $a0, $s0, $zero
/* 6BC730 80218BA0 8E250000 */  lw        $a1, ($s1)
/* 6BC734 80218BA4 0C0B2026 */  jal       set_variable
/* 6BC738 80218BA8 0040302D */   daddu    $a2, $v0, $zero
/* 6BC73C 80218BAC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6BC740 80218BB0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6BC744 80218BB4 8FB00018 */  lw        $s0, 0x18($sp)
/* 6BC748 80218BB8 24020002 */  addiu     $v0, $zero, 2
/* 6BC74C 80218BBC 03E00008 */  jr        $ra
/* 6BC750 80218BC0 27BD0028 */   addiu    $sp, $sp, 0x28
