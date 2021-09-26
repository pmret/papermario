.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0068148
/* 36AA18 E0068148 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 36AA1C E006814C AFBF0010 */  sw        $ra, 0x10($sp)
/* 36AA20 E0068150 8C850000 */  lw        $a1, ($a0)
/* 36AA24 E0068154 8C83000C */  lw        $v1, 0xc($a0)
/* 36AA28 E0068158 30A20010 */  andi      $v0, $a1, 0x10
/* 36AA2C E006815C 10400005 */  beqz      $v0, .LE0068174
/* 36AA30 E0068160 2402FFEF */   addiu    $v0, $zero, -0x11
/* 36AA34 E0068164 00A21024 */  and       $v0, $a1, $v0
/* 36AA38 E0068168 AC820000 */  sw        $v0, ($a0)
/* 36AA3C E006816C 2402000A */  addiu     $v0, $zero, 0xa
/* 36AA40 E0068170 AC62001C */  sw        $v0, 0x1c($v1)
.LE0068174:
/* 36AA44 E0068174 8C65001C */  lw        $a1, 0x1c($v1)
/* 36AA48 E0068178 28A2000B */  slti      $v0, $a1, 0xb
/* 36AA4C E006817C 10400002 */  beqz      $v0, .LE0068188
/* 36AA50 E0068180 24A2FFFF */   addiu    $v0, $a1, -1
/* 36AA54 E0068184 AC62001C */  sw        $v0, 0x1c($v1)
.LE0068188:
/* 36AA58 E0068188 8C620020 */  lw        $v0, 0x20($v1)
/* 36AA5C E006818C 8C65001C */  lw        $a1, 0x1c($v1)
/* 36AA60 E0068190 24420001 */  addiu     $v0, $v0, 1
/* 36AA64 E0068194 04A10005 */  bgez      $a1, .LE00681AC
/* 36AA68 E0068198 AC620020 */   sw       $v0, 0x20($v1)
/* 36AA6C E006819C 0C080128 */  jal       shim_remove_effect
/* 36AA70 E00681A0 00000000 */   nop
/* 36AA74 E00681A4 0801A073 */  j         .LE00681CC
/* 36AA78 E00681A8 00000000 */   nop
.LE00681AC:
/* 36AA7C E00681AC 28A2000A */  slti      $v0, $a1, 0xa
/* 36AA80 E00681B0 10400006 */  beqz      $v0, .LE00681CC
/* 36AA84 E00681B4 00000000 */   nop
/* 36AA88 E00681B8 8C620018 */  lw        $v0, 0x18($v1)
/* 36AA8C E00681BC 2442FFE7 */  addiu     $v0, $v0, -0x19
/* 36AA90 E00681C0 04410002 */  bgez      $v0, .LE00681CC
/* 36AA94 E00681C4 AC620018 */   sw       $v0, 0x18($v1)
/* 36AA98 E00681C8 AC600018 */  sw        $zero, 0x18($v1)
.LE00681CC:
/* 36AA9C E00681CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 36AAA0 E00681D0 03E00008 */  jr        $ra
/* 36AAA4 E00681D4 27BD0018 */   addiu    $sp, $sp, 0x18
