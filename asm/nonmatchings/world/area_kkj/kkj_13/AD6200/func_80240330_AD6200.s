.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240330_AD6200
/* AD6200 80240330 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AD6204 80240334 AFB00018 */  sw        $s0, 0x18($sp)
/* AD6208 80240338 0080802D */  daddu     $s0, $a0, $zero
/* AD620C 8024033C AFBF001C */  sw        $ra, 0x1c($sp)
/* AD6210 80240340 F7B40020 */  sdc1      $f20, 0x20($sp)
/* AD6214 80240344 0C00EAD2 */  jal       get_npc_safe
/* AD6218 80240348 24040001 */   addiu    $a0, $zero, 1
/* AD621C 8024034C 2404023D */  addiu     $a0, $zero, 0x23d
/* AD6220 80240350 C4420038 */  lwc1      $f2, 0x38($v0)
/* AD6224 80240354 C454003C */  lwc1      $f20, 0x3c($v0)
/* AD6228 80240358 C4400040 */  lwc1      $f0, 0x40($v0)
/* AD622C 8024035C 44061000 */  mfc1      $a2, $f2
/* AD6230 80240360 4407A000 */  mfc1      $a3, $f20
/* AD6234 80240364 0000282D */  daddu     $a1, $zero, $zero
/* AD6238 80240368 0C05267B */  jal       func_801499EC
/* AD623C 8024036C E7A00010 */   swc1     $f0, 0x10($sp)
/* AD6240 80240370 4600A10D */  trunc.w.s $f4, $f20
/* AD6244 80240374 E6040084 */  swc1      $f4, 0x84($s0)
/* AD6248 80240378 8FBF001C */  lw        $ra, 0x1c($sp)
/* AD624C 8024037C 8FB00018 */  lw        $s0, 0x18($sp)
/* AD6250 80240380 D7B40020 */  ldc1      $f20, 0x20($sp)
/* AD6254 80240384 24020002 */  addiu     $v0, $zero, 2
/* AD6258 80240388 03E00008 */  jr        $ra
/* AD625C 8024038C 27BD0028 */   addiu    $sp, $sp, 0x28
