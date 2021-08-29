.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240264_B06C64
/* B06C64 80240264 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B06C68 80240268 AFB1001C */  sw        $s1, 0x1c($sp)
/* B06C6C 8024026C 0080882D */  daddu     $s1, $a0, $zero
/* B06C70 80240270 AFBF0020 */  sw        $ra, 0x20($sp)
/* B06C74 80240274 AFB00018 */  sw        $s0, 0x18($sp)
/* B06C78 80240278 F7B80038 */  sdc1      $f24, 0x38($sp)
/* B06C7C 8024027C F7B60030 */  sdc1      $f22, 0x30($sp)
/* B06C80 80240280 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B06C84 80240284 8E30000C */  lw        $s0, 0xc($s1)
/* B06C88 80240288 8E050000 */  lw        $a1, ($s0)
/* B06C8C 8024028C 0C0B210B */  jal       evt_get_float_variable
/* B06C90 80240290 26100004 */   addiu    $s0, $s0, 4
/* B06C94 80240294 8E050000 */  lw        $a1, ($s0)
/* B06C98 80240298 26100004 */  addiu     $s0, $s0, 4
/* B06C9C 8024029C 0220202D */  daddu     $a0, $s1, $zero
/* B06CA0 802402A0 0C0B210B */  jal       evt_get_float_variable
/* B06CA4 802402A4 46000606 */   mov.s    $f24, $f0
/* B06CA8 802402A8 8E050000 */  lw        $a1, ($s0)
/* B06CAC 802402AC 26100004 */  addiu     $s0, $s0, 4
/* B06CB0 802402B0 0220202D */  daddu     $a0, $s1, $zero
/* B06CB4 802402B4 0C0B210B */  jal       evt_get_float_variable
/* B06CB8 802402B8 46000586 */   mov.s    $f22, $f0
/* B06CBC 802402BC 0220202D */  daddu     $a0, $s1, $zero
/* B06CC0 802402C0 8E050000 */  lw        $a1, ($s0)
/* B06CC4 802402C4 0C0B1EAF */  jal       get_variable
/* B06CC8 802402C8 46000506 */   mov.s    $f20, $f0
/* B06CCC 802402CC 4405C000 */  mfc1      $a1, $f24
/* B06CD0 802402D0 4406B000 */  mfc1      $a2, $f22
/* B06CD4 802402D4 4407A000 */  mfc1      $a3, $f20
/* B06CD8 802402D8 0000202D */  daddu     $a0, $zero, $zero
/* B06CDC 802402DC 0C01C094 */  jal       playFX_1A
/* B06CE0 802402E0 AFA20010 */   sw       $v0, 0x10($sp)
/* B06CE4 802402E4 8FBF0020 */  lw        $ra, 0x20($sp)
/* B06CE8 802402E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* B06CEC 802402EC 8FB00018 */  lw        $s0, 0x18($sp)
/* B06CF0 802402F0 D7B80038 */  ldc1      $f24, 0x38($sp)
/* B06CF4 802402F4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* B06CF8 802402F8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B06CFC 802402FC 24020002 */  addiu     $v0, $zero, 2
/* B06D00 80240300 03E00008 */  jr        $ra
/* B06D04 80240304 27BD0040 */   addiu    $sp, $sp, 0x40
/* B06D08 80240308 00000000 */  nop
/* B06D0C 8024030C 00000000 */  nop
