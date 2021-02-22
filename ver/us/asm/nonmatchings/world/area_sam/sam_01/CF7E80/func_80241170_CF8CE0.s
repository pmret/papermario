.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241170_CF8CE0
/* CF8CE0 80241170 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF8CE4 80241174 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF8CE8 80241178 8C82000C */  lw        $v0, 0xc($a0)
/* CF8CEC 8024117C 0C0B1EAF */  jal       get_variable
/* CF8CF0 80241180 8C450000 */   lw       $a1, ($v0)
/* CF8CF4 80241184 0040202D */  daddu     $a0, $v0, $zero
/* CF8CF8 80241188 3C028025 */  lui       $v0, %hi(D_8024DF18)
/* CF8CFC 8024118C 8C42DF18 */  lw        $v0, %lo(D_8024DF18)($v0)
/* CF8D00 80241190 24030001 */  addiu     $v1, $zero, 1
/* CF8D04 80241194 8C45000C */  lw        $a1, 0xc($v0)
/* CF8D08 80241198 1083000D */  beq       $a0, $v1, .L802411D0
/* CF8D0C 8024119C 28820002 */   slti     $v0, $a0, 2
/* CF8D10 802411A0 10400005 */  beqz      $v0, .L802411B8
/* CF8D14 802411A4 24020002 */   addiu    $v0, $zero, 2
/* CF8D18 802411A8 10800007 */  beqz      $a0, .L802411C8
/* CF8D1C 802411AC 240200C0 */   addiu    $v0, $zero, 0xc0
/* CF8D20 802411B0 08090478 */  j         .L802411E0
/* CF8D24 802411B4 ACA00038 */   sw       $zero, 0x38($a1)
.L802411B8:
/* CF8D28 802411B8 10820008 */  beq       $a0, $v0, .L802411DC
/* CF8D2C 802411BC 24020040 */   addiu    $v0, $zero, 0x40
/* CF8D30 802411C0 08090478 */  j         .L802411E0
/* CF8D34 802411C4 ACA00038 */   sw       $zero, 0x38($a1)
.L802411C8:
/* CF8D38 802411C8 08090478 */  j         .L802411E0
/* CF8D3C 802411CC ACA20038 */   sw       $v0, 0x38($a1)
.L802411D0:
/* CF8D40 802411D0 24020080 */  addiu     $v0, $zero, 0x80
/* CF8D44 802411D4 08090478 */  j         .L802411E0
/* CF8D48 802411D8 ACA20038 */   sw       $v0, 0x38($a1)
.L802411DC:
/* CF8D4C 802411DC ACA20038 */  sw        $v0, 0x38($a1)
.L802411E0:
/* CF8D50 802411E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8D54 802411E4 24020002 */  addiu     $v0, $zero, 2
/* CF8D58 802411E8 03E00008 */  jr        $ra
/* CF8D5C 802411EC 27BD0018 */   addiu    $sp, $sp, 0x18
