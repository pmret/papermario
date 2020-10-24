.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243B98_C43948
/* C43948 80243B98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C4394C 80243B9C AFBF0010 */  sw        $ra, 0x10($sp)
/* C43950 80243BA0 0C00FB5A */  jal       get_enemy_safe
/* C43954 80243BA4 24040009 */   addiu    $a0, $zero, 9
/* C43958 80243BA8 10400016 */  beqz      $v0, .L80243C04
/* C4395C 80243BAC 24020002 */   addiu    $v0, $zero, 2
/* C43960 80243BB0 0C00FB3A */  jal       get_enemy
/* C43964 80243BB4 24040009 */   addiu    $a0, $zero, 9
/* C43968 80243BB8 8C4400D0 */  lw        $a0, 0xd0($v0)
/* C4396C 80243BBC 24030002 */  addiu     $v1, $zero, 2
/* C43970 80243BC0 AC830000 */  sw        $v1, ($a0)
/* C43974 80243BC4 8C4400D0 */  lw        $a0, 0xd0($v0)
/* C43978 80243BC8 2403FE3E */  addiu     $v1, $zero, -0x1c2
/* C4397C 80243BCC AC830004 */  sw        $v1, 4($a0)
/* C43980 80243BD0 8C4300D0 */  lw        $v1, 0xd0($v0)
/* C43984 80243BD4 AC600008 */  sw        $zero, 8($v1)
/* C43988 80243BD8 8C4300D0 */  lw        $v1, 0xd0($v0)
/* C4398C 80243BDC 240500AF */  addiu     $a1, $zero, 0xaf
/* C43990 80243BE0 AC65000C */  sw        $a1, 0xc($v1)
/* C43994 80243BE4 8C4400D0 */  lw        $a0, 0xd0($v0)
/* C43998 80243BE8 2403012C */  addiu     $v1, $zero, 0x12c
/* C4399C 80243BEC AC830010 */  sw        $v1, 0x10($a0)
/* C439A0 80243BF0 8C4300D0 */  lw        $v1, 0xd0($v0)
/* C439A4 80243BF4 AC600014 */  sw        $zero, 0x14($v1)
/* C439A8 80243BF8 8C4300D0 */  lw        $v1, 0xd0($v0)
/* C439AC 80243BFC 24020002 */  addiu     $v0, $zero, 2
/* C439B0 80243C00 AC650018 */  sw        $a1, 0x18($v1)
.L80243C04:
/* C439B4 80243C04 8FBF0010 */  lw        $ra, 0x10($sp)
/* C439B8 80243C08 03E00008 */  jr        $ra
/* C439BC 80243C0C 27BD0018 */   addiu    $sp, $sp, 0x18
