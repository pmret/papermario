.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F140
/* 3A540 8005F140 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3A544 8005F144 AFB30054 */  sw        $s3, 0x54($sp)
/* 3A548 8005F148 0080982D */  daddu     $s3, $a0, $zero
/* 3A54C 8005F14C AFB20050 */  sw        $s2, 0x50($sp)
/* 3A550 8005F150 00A0902D */  daddu     $s2, $a1, $zero
/* 3A554 8005F154 AFB1004C */  sw        $s1, 0x4c($sp)
/* 3A558 8005F158 00C0882D */  daddu     $s1, $a2, $zero
/* 3A55C 8005F15C AFB00048 */  sw        $s0, 0x48($sp)
/* 3A560 8005F160 27B00028 */  addiu     $s0, $sp, 0x28
/* 3A564 8005F164 0200202D */  daddu     $a0, $s0, $zero
/* 3A568 8005F168 27A50040 */  addiu     $a1, $sp, 0x40
/* 3A56C 8005F16C AFBF0058 */  sw        $ra, 0x58($sp)
/* 3A570 8005F170 0C019554 */  jal       func_80065550
/* 3A574 8005F174 24060001 */   addiu    $a2, $zero, 1
/* 3A578 8005F178 0240202D */  daddu     $a0, $s2, $zero
/* 3A57C 8005F17C 0220282D */  daddu     $a1, $s1, $zero
/* 3A580 8005F180 A3A00012 */  sb        $zero, 0x12($sp)
/* 3A584 8005F184 0C0185BC */  jal       func_800616F0
/* 3A588 8005F188 AFB00014 */   sw       $s0, 0x14($sp)
/* 3A58C 8005F18C 0240202D */  daddu     $a0, $s2, $zero
/* 3A590 8005F190 0C0185E8 */  jal       func_800617A0
/* 3A594 8005F194 0220282D */   daddu    $a1, $s1, $zero
/* 3A598 8005F198 12200015 */  beqz      $s1, .L8005F1F0
/* 3A59C 8005F19C 00000000 */   nop
.L8005F1A0:
/* 3A5A0 8005F1A0 2E224001 */  sltiu     $v0, $s1, 0x4001
/* 3A5A4 8005F1A4 14400002 */  bnez      $v0, .L8005F1B0
/* 3A5A8 8005F1A8 0220802D */   daddu    $s0, $s1, $zero
/* 3A5AC 8005F1AC 24104000 */  addiu     $s0, $zero, 0x4000
.L8005F1B0:
/* 3A5B0 8005F1B0 27A50010 */  addiu     $a1, $sp, 0x10
/* 3A5B4 8005F1B4 3C04800A */  lui       $a0, %hi(D_8009A618)
/* 3A5B8 8005F1B8 8C84A618 */  lw        $a0, %lo(D_8009A618)($a0)
/* 3A5BC 8005F1BC 0000302D */  daddu     $a2, $zero, $zero
/* 3A5C0 8005F1C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 3A5C4 8005F1C4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3A5C8 8005F1C8 0C01837C */  jal       func_80060DF0
/* 3A5CC 8005F1CC AFB00020 */   sw       $s0, 0x20($sp)
/* 3A5D0 8005F1D0 27A40028 */  addiu     $a0, $sp, 0x28
/* 3A5D4 8005F1D4 27A50040 */  addiu     $a1, $sp, 0x40
/* 3A5D8 8005F1D8 0C0195B0 */  jal       func_800656C0
/* 3A5DC 8005F1DC 24060001 */   addiu    $a2, $zero, 1
/* 3A5E0 8005F1E0 02709821 */  addu      $s3, $s3, $s0
/* 3A5E4 8005F1E4 02308823 */  subu      $s1, $s1, $s0
/* 3A5E8 8005F1E8 1620FFED */  bnez      $s1, .L8005F1A0
/* 3A5EC 8005F1EC 02509021 */   addu     $s2, $s2, $s0
.L8005F1F0:
/* 3A5F0 8005F1F0 8FBF0058 */  lw        $ra, 0x58($sp)
/* 3A5F4 8005F1F4 8FB30054 */  lw        $s3, 0x54($sp)
/* 3A5F8 8005F1F8 8FB20050 */  lw        $s2, 0x50($sp)
/* 3A5FC 8005F1FC 8FB1004C */  lw        $s1, 0x4c($sp)
/* 3A600 8005F200 8FB00048 */  lw        $s0, 0x48($sp)
/* 3A604 8005F204 03E00008 */  jr        $ra
/* 3A608 8005F208 27BD0060 */   addiu    $sp, $sp, 0x60
/* 3A60C 8005F20C 00000000 */  nop
