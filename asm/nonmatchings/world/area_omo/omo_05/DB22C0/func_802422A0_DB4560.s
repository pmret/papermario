.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422A0_DB4560
/* DB4560 802422A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB4564 802422A4 AFB00010 */  sw        $s0, 0x10($sp)
/* DB4568 802422A8 0080802D */  daddu     $s0, $a0, $zero
/* DB456C 802422AC AFBF0014 */  sw        $ra, 0x14($sp)
/* DB4570 802422B0 8E02000C */  lw        $v0, 0xc($s0)
/* DB4574 802422B4 0C0B1EAF */  jal       get_variable
/* DB4578 802422B8 8C450000 */   lw       $a1, ($v0)
/* DB457C 802422BC 0040202D */  daddu     $a0, $v0, $zero
/* DB4580 802422C0 3C038008 */  lui       $v1, %hi(gItemTable)
/* DB4584 802422C4 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* DB4588 802422C8 00041140 */  sll       $v0, $a0, 5
/* DB458C 802422CC 00431821 */  addu      $v1, $v0, $v1
/* DB4590 802422D0 240200C1 */  addiu     $v0, $zero, 0xc1
/* DB4594 802422D4 10820005 */  beq       $a0, $v0, .L802422EC
/* DB4598 802422D8 240200D2 */   addiu    $v0, $zero, 0xd2
/* DB459C 802422DC 10820003 */  beq       $a0, $v0, .L802422EC
/* DB45A0 802422E0 240200B7 */   addiu    $v0, $zero, 0xb7
/* DB45A4 802422E4 14820004 */  bne       $a0, $v0, .L802422F8
/* DB45A8 802422E8 00000000 */   nop
.L802422EC:
/* DB45AC 802422EC 24020002 */  addiu     $v0, $zero, 2
/* DB45B0 802422F0 080908C5 */  j         .L80242314
/* DB45B4 802422F4 AE0200A8 */   sw       $v0, 0xa8($s0)
.L802422F8:
/* DB45B8 802422F8 94620018 */  lhu       $v0, 0x18($v1)
/* DB45BC 802422FC 30420080 */  andi      $v0, $v0, 0x80
/* DB45C0 80242300 10400003 */  beqz      $v0, .L80242310
/* DB45C4 80242304 24020001 */   addiu    $v0, $zero, 1
/* DB45C8 80242308 080908C5 */  j         .L80242314
/* DB45CC 8024230C AE0200A8 */   sw       $v0, 0xa8($s0)
.L80242310:
/* DB45D0 80242310 AE0000A8 */  sw        $zero, 0xa8($s0)
.L80242314:
/* DB45D4 80242314 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB45D8 80242318 8FB00010 */  lw        $s0, 0x10($sp)
/* DB45DC 8024231C 24020002 */  addiu     $v0, $zero, 2
/* DB45E0 80242320 03E00008 */  jr        $ra
/* DB45E4 80242324 27BD0018 */   addiu    $sp, $sp, 0x18
