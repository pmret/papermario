.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021C09C_6A329C
/* 6A329C 8021C09C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A32A0 8021C0A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A32A4 8021C0A4 0080802D */  daddu     $s0, $a0, $zero
/* 6A32A8 8021C0A8 10A00003 */  beqz      $a1, .L8021C0B8
/* 6A32AC 8021C0AC AFBF0014 */   sw       $ra, 0x14($sp)
/* 6A32B0 8021C0B0 24020014 */  addiu     $v0, $zero, 0x14
/* 6A32B4 8021C0B4 AE020070 */  sw        $v0, 0x70($s0)
.L8021C0B8:
/* 6A32B8 8021C0B8 0000202D */  daddu     $a0, $zero, $zero
/* 6A32BC 8021C0BC 0080282D */  daddu     $a1, $a0, $zero
/* 6A32C0 8021C0C0 8E020070 */  lw        $v0, 0x70($s0)
/* 6A32C4 8021C0C4 0080302D */  daddu     $a2, $a0, $zero
/* 6A32C8 8021C0C8 00023880 */  sll       $a3, $v0, 2
/* 6A32CC 8021C0CC 00E23821 */  addu      $a3, $a3, $v0
/* 6A32D0 8021C0D0 00073840 */  sll       $a3, $a3, 1
/* 6A32D4 8021C0D4 0C046F97 */  jal       set_background_color_blend
/* 6A32D8 8021C0D8 30E700FE */   andi     $a3, $a3, 0xfe
/* 6A32DC 8021C0DC 8E020070 */  lw        $v0, 0x70($s0)
/* 6A32E0 8021C0E0 2442FFFF */  addiu     $v0, $v0, -1
/* 6A32E4 8021C0E4 10400003 */  beqz      $v0, .L8021C0F4
/* 6A32E8 8021C0E8 AE020070 */   sw       $v0, 0x70($s0)
/* 6A32EC 8021C0EC 08087043 */  j         .L8021C10C
/* 6A32F0 8021C0F0 0000102D */   daddu    $v0, $zero, $zero
.L8021C0F4:
/* 6A32F4 8021C0F4 0000202D */  daddu     $a0, $zero, $zero
/* 6A32F8 8021C0F8 0080282D */  daddu     $a1, $a0, $zero
/* 6A32FC 8021C0FC 0080302D */  daddu     $a2, $a0, $zero
/* 6A3300 8021C100 0C046F97 */  jal       set_background_color_blend
/* 6A3304 8021C104 0080382D */   daddu    $a3, $a0, $zero
/* 6A3308 8021C108 24020002 */  addiu     $v0, $zero, 2
.L8021C10C:
/* 6A330C 8021C10C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6A3310 8021C110 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A3314 8021C114 03E00008 */  jr        $ra
/* 6A3318 8021C118 27BD0018 */   addiu    $sp, $sp, 0x18
