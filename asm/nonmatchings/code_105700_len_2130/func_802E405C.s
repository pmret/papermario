.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E405C
/* 1058DC 802E405C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1058E0 802E4060 3C013F80 */  lui       $at, 0x3f80
/* 1058E4 802E4064 44810000 */  mtc1      $at, $f0
/* 1058E8 802E4068 2402003C */  addiu     $v0, $zero, 0x3c
/* 1058EC 802E406C AFBF0018 */  sw        $ra, 0x18($sp)
/* 1058F0 802E4070 AFA20014 */  sw        $v0, 0x14($sp)
/* 1058F4 802E4074 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1058F8 802E4078 8C850048 */  lw        $a1, 0x48($a0)
/* 1058FC 802E407C 8C86004C */  lw        $a2, 0x4c($a0)
/* 105900 802E4080 8C870050 */  lw        $a3, 0x50($a0)
/* 105904 802E4084 0C01C88C */  jal       func_80072230
/* 105908 802E4088 0000202D */   daddu    $a0, $zero, $zero
/* 10590C 802E408C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 105910 802E4090 3C01802F */  lui       $at, %hi(D_802EB3B0)
/* 105914 802E4094 AC22B3B0 */  sw        $v0, %lo(D_802EB3B0)($at)
/* 105918 802E4098 03E00008 */  jr        $ra
/* 10591C 802E409C 27BD0020 */   addiu    $sp, $sp, 0x20
