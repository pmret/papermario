.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetTexPanOffset
/* EDD14 802C9364 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EDD18 802C9368 AFB10014 */  sw        $s1, 0x14($sp)
/* EDD1C 802C936C 0080882D */  daddu     $s1, $a0, $zero
/* EDD20 802C9370 AFBF0020 */  sw        $ra, 0x20($sp)
/* EDD24 802C9374 AFB3001C */  sw        $s3, 0x1c($sp)
/* EDD28 802C9378 AFB20018 */  sw        $s2, 0x18($sp)
/* EDD2C 802C937C AFB00010 */  sw        $s0, 0x10($sp)
/* EDD30 802C9380 8E30000C */  lw        $s0, 0xc($s1)
/* EDD34 802C9384 8E050000 */  lw        $a1, ($s0)
/* EDD38 802C9388 0C0B1EAF */  jal       get_variable
/* EDD3C 802C938C 26100004 */   addiu    $s0, $s0, 4
/* EDD40 802C9390 8E050000 */  lw        $a1, ($s0)
/* EDD44 802C9394 26100004 */  addiu     $s0, $s0, 4
/* EDD48 802C9398 0220202D */  daddu     $a0, $s1, $zero
/* EDD4C 802C939C 0C0B1EAF */  jal       get_variable
/* EDD50 802C93A0 0040982D */   daddu    $s3, $v0, $zero
/* EDD54 802C93A4 8E050000 */  lw        $a1, ($s0)
/* EDD58 802C93A8 26100004 */  addiu     $s0, $s0, 4
/* EDD5C 802C93AC 0220202D */  daddu     $a0, $s1, $zero
/* EDD60 802C93B0 0C0B1EAF */  jal       get_variable
/* EDD64 802C93B4 0040902D */   daddu    $s2, $v0, $zero
/* EDD68 802C93B8 0220202D */  daddu     $a0, $s1, $zero
/* EDD6C 802C93BC 8E050000 */  lw        $a1, ($s0)
/* EDD70 802C93C0 0C0B1EAF */  jal       get_variable
/* EDD74 802C93C4 0040802D */   daddu    $s0, $v0, $zero
/* EDD78 802C93C8 16400009 */  bnez      $s2, .L802C93F0
/* EDD7C 802C93CC 0040882D */   daddu    $s1, $v0, $zero
/* EDD80 802C93D0 0260202D */  daddu     $a0, $s3, $zero
/* EDD84 802C93D4 0C046F07 */  jal       set_main_pan_u
/* EDD88 802C93D8 0200282D */   daddu    $a1, $s0, $zero
/* EDD8C 802C93DC 0260202D */  daddu     $a0, $s3, $zero
/* EDD90 802C93E0 0C046F0D */  jal       set_main_pan_v
/* EDD94 802C93E4 0220282D */   daddu    $a1, $s1, $zero
/* EDD98 802C93E8 080B2502 */  j         .L802C9408
/* EDD9C 802C93EC 00000000 */   nop      
.L802C93F0:
/* EDDA0 802C93F0 0260202D */  daddu     $a0, $s3, $zero
/* EDDA4 802C93F4 0C046F13 */  jal       set_aux_pan_u
/* EDDA8 802C93F8 0200282D */   daddu    $a1, $s0, $zero
/* EDDAC 802C93FC 0260202D */  daddu     $a0, $s3, $zero
/* EDDB0 802C9400 0C046F19 */  jal       set_aux_pan_v
/* EDDB4 802C9404 0220282D */   daddu    $a1, $s1, $zero
.L802C9408:
/* EDDB8 802C9408 8FBF0020 */  lw        $ra, 0x20($sp)
/* EDDBC 802C940C 8FB3001C */  lw        $s3, 0x1c($sp)
/* EDDC0 802C9410 8FB20018 */  lw        $s2, 0x18($sp)
/* EDDC4 802C9414 8FB10014 */  lw        $s1, 0x14($sp)
/* EDDC8 802C9418 8FB00010 */  lw        $s0, 0x10($sp)
/* EDDCC 802C941C 24020002 */  addiu     $v0, $zero, 2
/* EDDD0 802C9420 03E00008 */  jr        $ra
/* EDDD4 802C9424 27BD0028 */   addiu    $sp, $sp, 0x28
