.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F420
/* 3A820 8005F420 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A824 8005F424 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A828 8005F428 8C83000C */  lw        $v1, 0xc($a0)
/* 3A82C 8005F42C 8C620008 */  lw        $v0, 8($v1)
/* 3A830 8005F430 8C650000 */  lw        $a1, ($v1)
/* 3A834 8005F434 9066000C */  lbu       $a2, 0xc($v1)
/* 3A838 8005F438 AFA20010 */  sw        $v0, 0x10($sp)
/* 3A83C 8005F43C 8C620010 */  lw        $v0, 0x10($v1)
/* 3A840 8005F440 AFA20014 */  sw        $v0, 0x14($sp)
/* 3A844 8005F444 8CA40000 */  lw        $a0, ($a1)
/* 3A848 8005F448 8CA50004 */  lw        $a1, 4($a1)
/* 3A84C 8005F44C 0C01A1F0 */  jal       func_800687C0
/* 3A850 8005F450 8C670004 */   lw       $a3, 4($v1)
/* 3A854 8005F454 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A858 8005F458 03E00008 */  jr        $ra
/* 3A85C 8005F45C 27BD0020 */   addiu    $sp, $sp, 0x20
