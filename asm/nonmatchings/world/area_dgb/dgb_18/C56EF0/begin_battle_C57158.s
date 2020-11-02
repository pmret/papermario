.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel begin_battle_C57158
/* C57158 80241218 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5715C 8024121C AFB00010 */  sw        $s0, 0x10($sp)
/* C57160 80241220 0080802D */  daddu     $s0, $a0, $zero
/* C57164 80241224 AFBF0014 */  sw        $ra, 0x14($sp)
/* C57168 80241228 8E02000C */  lw        $v0, 0xc($s0)
/* C5716C 8024122C 0C0B1EAF */  jal       get_variable
/* C57170 80241230 8C450000 */   lw       $a1, ($v0)
/* C57174 80241234 00021140 */  sll       $v0, $v0, 5
/* C57178 80241238 AE000084 */  sw        $zero, 0x84($s0)
/* C5717C 8024123C 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* C57180 80241240 00220821 */  addu      $at, $at, $v0
/* C57184 80241244 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* C57188 80241248 30420040 */  andi      $v0, $v0, 0x40
/* C5718C 8024124C 10400002 */  beqz      $v0, .L80241258
/* C57190 80241250 24020001 */   addiu    $v0, $zero, 1
/* C57194 80241254 AE020084 */  sw        $v0, 0x84($s0)
.L80241258:
/* C57198 80241258 8FBF0014 */  lw        $ra, 0x14($sp)
/* C5719C 8024125C 8FB00010 */  lw        $s0, 0x10($sp)
/* C571A0 80241260 24020002 */  addiu     $v0, $zero, 2
/* C571A4 80241264 03E00008 */  jr        $ra
/* C571A8 80241268 27BD0018 */   addiu    $sp, $sp, 0x18
/* C571AC 8024126C 00000000 */  nop       
