.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B8134
/* 3B7CB4 E00B8134 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B7CB8 E00B8138 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B7CBC E00B813C 8C830000 */  lw        $v1, ($a0)
/* 3B7CC0 E00B8140 8C86000C */  lw        $a2, 0xc($a0)
/* 3B7CC4 E00B8144 30620010 */  andi      $v0, $v1, 0x10
/* 3B7CC8 E00B8148 10400005 */  beqz      $v0, .LE00B8160
/* 3B7CCC E00B814C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3B7CD0 E00B8150 00621024 */  and       $v0, $v1, $v0
/* 3B7CD4 E00B8154 AC820000 */  sw        $v0, ($a0)
/* 3B7CD8 E00B8158 24020010 */  addiu     $v0, $zero, 0x10
/* 3B7CDC E00B815C ACC20010 */  sw        $v0, 0x10($a2)
.LE00B8160:
/* 3B7CE0 E00B8160 8CC30010 */  lw        $v1, 0x10($a2)
/* 3B7CE4 E00B8164 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3B7CE8 E00B8168 10400002 */  beqz      $v0, .LE00B8174
/* 3B7CEC E00B816C 2462FFFF */   addiu    $v0, $v1, -1
/* 3B7CF0 E00B8170 ACC20010 */  sw        $v0, 0x10($a2)
.LE00B8174:
/* 3B7CF4 E00B8174 8CC20014 */  lw        $v0, 0x14($a2)
/* 3B7CF8 E00B8178 8CC30010 */  lw        $v1, 0x10($a2)
/* 3B7CFC E00B817C 24450001 */  addiu     $a1, $v0, 1
/* 3B7D00 E00B8180 04610005 */  bgez      $v1, .LE00B8198
/* 3B7D04 E00B8184 ACC50014 */   sw       $a1, 0x14($a2)
/* 3B7D08 E00B8188 0C080128 */  jal       func_E02004A0
/* 3B7D0C E00B818C 00000000 */   nop
/* 3B7D10 E00B8190 0802E06B */  j         .LE00B81AC
/* 3B7D14 E00B8194 00000000 */   nop
.LE00B8198:
/* 3B7D18 E00B8198 28A20008 */  slti      $v0, $a1, 8
/* 3B7D1C E00B819C 10400003 */  beqz      $v0, .LE00B81AC
/* 3B7D20 E00B81A0 00051140 */   sll      $v0, $a1, 5
/* 3B7D24 E00B81A4 2442001F */  addiu     $v0, $v0, 0x1f
/* 3B7D28 E00B81A8 ACC20024 */  sw        $v0, 0x24($a2)
.LE00B81AC:
/* 3B7D2C E00B81AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B7D30 E00B81B0 03E00008 */  jr        $ra
/* 3B7D34 E00B81B4 27BD0018 */   addiu    $sp, $sp, 0x18
