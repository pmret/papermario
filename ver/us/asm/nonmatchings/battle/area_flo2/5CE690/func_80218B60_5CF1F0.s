.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B60_5CF1F0
/* 5CF1F0 80218B60 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 5CF1F4 80218B64 AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF1F8 80218B68 0080882D */  daddu     $s1, $a0, $zero
/* 5CF1FC 80218B6C AFBF0028 */  sw        $ra, 0x28($sp)
/* 5CF200 80218B70 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF204 80218B74 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF208 80218B78 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF20C 80218B7C F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5CF210 80218B80 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5CF214 80218B84 8E30000C */  lw        $s0, 0xc($s1)
/* 5CF218 80218B88 8E050000 */  lw        $a1, ($s0)
/* 5CF21C 80218B8C 0C0B1EAF */  jal       evt_get_variable
/* 5CF220 80218B90 26100004 */   addiu    $s0, $s0, 4
/* 5CF224 80218B94 8E050000 */  lw        $a1, ($s0)
/* 5CF228 80218B98 26100004 */  addiu     $s0, $s0, 4
/* 5CF22C 80218B9C 0220202D */  daddu     $a0, $s1, $zero
/* 5CF230 80218BA0 0C0B210B */  jal       evt_get_float_variable
/* 5CF234 80218BA4 0040982D */   daddu    $s3, $v0, $zero
/* 5CF238 80218BA8 8E050000 */  lw        $a1, ($s0)
/* 5CF23C 80218BAC 26100004 */  addiu     $s0, $s0, 4
/* 5CF240 80218BB0 0220202D */  daddu     $a0, $s1, $zero
/* 5CF244 80218BB4 0C0B210B */  jal       evt_get_float_variable
/* 5CF248 80218BB8 46000586 */   mov.s    $f22, $f0
/* 5CF24C 80218BBC 8E050000 */  lw        $a1, ($s0)
/* 5CF250 80218BC0 26100004 */  addiu     $s0, $s0, 4
/* 5CF254 80218BC4 0220202D */  daddu     $a0, $s1, $zero
/* 5CF258 80218BC8 0C0B1EAF */  jal       evt_get_variable
/* 5CF25C 80218BCC 46000506 */   mov.s    $f20, $f0
/* 5CF260 80218BD0 8E050000 */  lw        $a1, ($s0)
/* 5CF264 80218BD4 26100004 */  addiu     $s0, $s0, 4
/* 5CF268 80218BD8 0220202D */  daddu     $a0, $s1, $zero
/* 5CF26C 80218BDC 0C0B1EAF */  jal       evt_get_variable
/* 5CF270 80218BE0 0040902D */   daddu    $s2, $v0, $zero
/* 5CF274 80218BE4 0260202D */  daddu     $a0, $s3, $zero
/* 5CF278 80218BE8 4405B000 */  mfc1      $a1, $f22
/* 5CF27C 80218BEC 4406A000 */  mfc1      $a2, $f20
/* 5CF280 80218BF0 0240382D */  daddu     $a3, $s2, $zero
/* 5CF284 80218BF4 0C00A8ED */  jal       update_lerp
/* 5CF288 80218BF8 AFA20010 */   sw       $v0, 0x10($sp)
/* 5CF28C 80218BFC 8E050000 */  lw        $a1, ($s0)
/* 5CF290 80218C00 44060000 */  mfc1      $a2, $f0
/* 5CF294 80218C04 0C0B2190 */  jal       evt_set_float_variable
/* 5CF298 80218C08 0220202D */   daddu    $a0, $s1, $zero
/* 5CF29C 80218C0C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF2A0 80218C10 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF2A4 80218C14 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF2A8 80218C18 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF2AC 80218C1C 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF2B0 80218C20 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5CF2B4 80218C24 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5CF2B8 80218C28 24020002 */  addiu     $v0, $zero, 2
/* 5CF2BC 80218C2C 03E00008 */  jr        $ra
/* 5CF2C0 80218C30 27BD0040 */   addiu    $sp, $sp, 0x40
/* 5CF2C4 80218C34 00000000 */  nop
/* 5CF2C8 80218C38 00000000 */  nop
/* 5CF2CC 80218C3C 00000000 */  nop
