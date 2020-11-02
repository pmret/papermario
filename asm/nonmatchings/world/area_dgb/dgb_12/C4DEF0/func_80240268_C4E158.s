.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240268_C4E158
/* C4E158 80240268 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C4E15C 8024026C AFB00010 */  sw        $s0, 0x10($sp)
/* C4E160 80240270 0080802D */  daddu     $s0, $a0, $zero
/* C4E164 80240274 AFBF0014 */  sw        $ra, 0x14($sp)
/* C4E168 80240278 8E02000C */  lw        $v0, 0xc($s0)
/* C4E16C 8024027C 0C0B1EAF */  jal       get_variable
/* C4E170 80240280 8C450000 */   lw       $a1, ($v0)
/* C4E174 80240284 00021140 */  sll       $v0, $v0, 5
/* C4E178 80240288 AE000084 */  sw        $zero, 0x84($s0)
/* C4E17C 8024028C 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* C4E180 80240290 00220821 */  addu      $at, $at, $v0
/* C4E184 80240294 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* C4E188 80240298 30420040 */  andi      $v0, $v0, 0x40
/* C4E18C 8024029C 10400002 */  beqz      $v0, .L802402A8
/* C4E190 802402A0 24020001 */   addiu    $v0, $zero, 1
/* C4E194 802402A4 AE020084 */  sw        $v0, 0x84($s0)
.L802402A8:
/* C4E198 802402A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* C4E19C 802402AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C4E1A0 802402B0 24020002 */  addiu     $v0, $zero, 2
/* C4E1A4 802402B4 03E00008 */  jr        $ra
/* C4E1A8 802402B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* C4E1AC 802402BC 00000000 */  nop       
