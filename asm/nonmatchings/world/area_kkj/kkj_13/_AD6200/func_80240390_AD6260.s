.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240390_AD6260
/* AD6260 80240390 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AD6264 80240394 AFB00018 */  sw        $s0, 0x18($sp)
/* AD6268 80240398 0080802D */  daddu     $s0, $a0, $zero
/* AD626C 8024039C AFBF001C */  sw        $ra, 0x1c($sp)
/* AD6270 802403A0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* AD6274 802403A4 0C00EAD2 */  jal       get_npc_safe
/* AD6278 802403A8 24040001 */   addiu    $a0, $zero, 1
/* AD627C 802403AC 2404023D */  addiu     $a0, $zero, 0x23d
/* AD6280 802403B0 C4420038 */  lwc1      $f2, 0x38($v0)
/* AD6284 802403B4 C454003C */  lwc1      $f20, 0x3c($v0)
/* AD6288 802403B8 C4400040 */  lwc1      $f0, 0x40($v0)
/* AD628C 802403BC 44061000 */  mfc1      $a2, $f2
/* AD6290 802403C0 4407A000 */  mfc1      $a3, $f20
/* AD6294 802403C4 0000282D */  daddu     $a1, $zero, $zero
/* AD6298 802403C8 0C05267B */  jal       func_801499EC
/* AD629C 802403CC E7A00010 */   swc1     $f0, 0x10($sp)
/* AD62A0 802403D0 4600A10D */  trunc.w.s $f4, $f20
/* AD62A4 802403D4 E6040084 */  swc1      $f4, 0x84($s0)
/* AD62A8 802403D8 8FBF001C */  lw        $ra, 0x1c($sp)
/* AD62AC 802403DC 8FB00018 */  lw        $s0, 0x18($sp)
/* AD62B0 802403E0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* AD62B4 802403E4 24020002 */  addiu     $v0, $zero, 2
/* AD62B8 802403E8 03E00008 */  jr        $ra
/* AD62BC 802403EC 27BD0028 */   addiu    $sp, $sp, 0x28
