.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BFC_A4033C
/* A4033C 80240BFC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A40340 80240C00 AFB00010 */  sw        $s0, 0x10($sp)
/* A40344 80240C04 0080802D */  daddu     $s0, $a0, $zero
/* A40348 80240C08 10A00002 */  beqz      $a1, .L80240C14
/* A4034C 80240C0C AFBF0014 */   sw       $ra, 0x14($sp)
/* A40350 80240C10 AE000074 */  sw        $zero, 0x74($s0)
.L80240C14:
/* A40354 80240C14 0000202D */  daddu     $a0, $zero, $zero
/* A40358 80240C18 240500D0 */  addiu     $a1, $zero, 0xd0
/* A4035C 80240C1C 00A0302D */  daddu     $a2, $a1, $zero
/* A40360 80240C20 0C04DF84 */  jal       set_screen_overlay_color
/* A40364 80240C24 00A0382D */   daddu    $a3, $a1, $zero
/* A40368 80240C28 C6000074 */  lwc1      $f0, 0x74($s0)
/* A4036C 80240C2C 46800020 */  cvt.s.w   $f0, $f0
/* A40370 80240C30 44050000 */  mfc1      $a1, $f0
/* A40374 80240C34 0C04DF62 */  jal       set_screen_overlay_params_front
/* A40378 80240C38 24040001 */   addiu    $a0, $zero, 1
/* A4037C 80240C3C 8E020074 */  lw        $v0, 0x74($s0)
/* A40380 80240C40 240300FF */  addiu     $v1, $zero, 0xff
/* A40384 80240C44 14430003 */  bne       $v0, $v1, .L80240C54
/* A40388 80240C48 24420007 */   addiu    $v0, $v0, 7
/* A4038C 80240C4C 0809031A */  j         .L80240C68
/* A40390 80240C50 24020002 */   addiu    $v0, $zero, 2
.L80240C54:
/* A40394 80240C54 AE020074 */  sw        $v0, 0x74($s0)
/* A40398 80240C58 28420100 */  slti      $v0, $v0, 0x100
/* A4039C 80240C5C 50400001 */  beql      $v0, $zero, .L80240C64
/* A403A0 80240C60 AE030074 */   sw       $v1, 0x74($s0)
.L80240C64:
/* A403A4 80240C64 0000102D */  daddu     $v0, $zero, $zero
.L80240C68:
/* A403A8 80240C68 8FBF0014 */  lw        $ra, 0x14($sp)
/* A403AC 80240C6C 8FB00010 */  lw        $s0, 0x10($sp)
/* A403B0 80240C70 03E00008 */  jr        $ra
/* A403B4 80240C74 27BD0018 */   addiu    $sp, $sp, 0x18
/* A403B8 80240C78 00000000 */  nop
/* A403BC 80240C7C 00000000 */  nop
