.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A90_66A810
/* 66A810 80218A90 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66A814 80218A94 AFB00018 */  sw        $s0, 0x18($sp)
/* 66A818 80218A98 0080802D */  daddu     $s0, $a0, $zero
/* 66A81C 80218A9C 3C0542D4 */  lui       $a1, 0x42d4
/* 66A820 80218AA0 3C064310 */  lui       $a2, 0x4310
/* 66A824 80218AA4 0000202D */  daddu     $a0, $zero, $zero
/* 66A828 80218AA8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 66A82C 80218AAC AFB1001C */  sw        $s1, 0x1c($sp)
/* 66A830 80218AB0 8E11000C */  lw        $s1, 0xc($s0)
/* 66A834 80218AB4 3C013F80 */  lui       $at, 0x3f80
/* 66A838 80218AB8 44810000 */  mtc1      $at, $f0
/* 66A83C 80218ABC 0000382D */  daddu     $a3, $zero, $zero
/* 66A840 80218AC0 AFA00014 */  sw        $zero, 0x14($sp)
/* 66A844 80218AC4 0C01C844 */  jal       playFX_6C
/* 66A848 80218AC8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 66A84C 80218ACC 0200202D */  daddu     $a0, $s0, $zero
/* 66A850 80218AD0 8E250000 */  lw        $a1, ($s1)
/* 66A854 80218AD4 0C0B2026 */  jal       evt_set_variable
/* 66A858 80218AD8 0040302D */   daddu    $a2, $v0, $zero
/* 66A85C 80218ADC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 66A860 80218AE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 66A864 80218AE4 8FB00018 */  lw        $s0, 0x18($sp)
/* 66A868 80218AE8 24020002 */  addiu     $v0, $zero, 2
/* 66A86C 80218AEC 03E00008 */  jr        $ra
/* 66A870 80218AF0 27BD0028 */   addiu    $sp, $sp, 0x28
