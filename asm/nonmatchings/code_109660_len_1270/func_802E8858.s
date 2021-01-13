.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E8858
/* 10A0D8 802E8858 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10A0DC 802E885C AFB00010 */  sw        $s0, 0x10($sp)
/* 10A0E0 802E8860 0080802D */  daddu     $s0, $a0, $zero
/* 10A0E4 802E8864 AFBF0014 */  sw        $ra, 0x14($sp)
/* 10A0E8 802E8868 92020006 */  lbu       $v0, 6($s0)
/* 10A0EC 802E886C 30420001 */  andi      $v0, $v0, 1
/* 10A0F0 802E8870 1040000C */  beqz      $v0, .L802E88A4
/* 10A0F4 802E8874 0000202D */   daddu    $a0, $zero, $zero
/* 10A0F8 802E8878 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 10A0FC 802E887C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 10A100 802E8880 804300B4 */  lb        $v1, 0xb4($v0)
/* 10A104 802E8884 2402000E */  addiu     $v0, $zero, 0xe
/* 10A108 802E8888 10620003 */  beq       $v1, $v0, .L802E8898
/* 10A10C 802E888C 24020010 */   addiu    $v0, $zero, 0x10
/* 10A110 802E8890 14620004 */  bne       $v1, $v0, .L802E88A4
/* 10A114 802E8894 00000000 */   nop
.L802E8898:
/* 10A118 802E8898 0C039769 */  jal       set_action_state
/* 10A11C 802E889C 24040008 */   addiu    $a0, $zero, 8
/* 10A120 802E88A0 24040001 */  addiu     $a0, $zero, 1
.L802E88A4:
/* 10A124 802E88A4 1080000D */  beqz      $a0, .L802E88DC
/* 10A128 802E88A8 00000000 */   nop
/* 10A12C 802E88AC 0C0B9FDB */  jal       func_802E7F6C
/* 10A130 802E88B0 0200202D */   daddu    $a0, $s0, $zero
/* 10A134 802E88B4 3C05802F */  lui       $a1, %hi(D_802EAE7C)
/* 10A138 802E88B8 24A5AE7C */  addiu     $a1, $a1, %lo(D_802EAE7C)
/* 10A13C 802E88BC 0C0442F3 */  jal       func_80110BCC
/* 10A140 802E88C0 0200202D */   daddu    $a0, $s0, $zero
/* 10A144 802E88C4 0C04419E */  jal       func_80110678
/* 10A148 802E88C8 0200202D */   daddu    $a0, $s0, $zero
/* 10A14C 802E88CC 0C043F5A */  jal       func_8010FD68
/* 10A150 802E88D0 0200202D */   daddu    $a0, $s0, $zero
/* 10A154 802E88D4 0C05272D */  jal       play_sound
/* 10A158 802E88D8 240420AE */   addiu    $a0, $zero, 0x20ae
.L802E88DC:
/* 10A15C 802E88DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 10A160 802E88E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 10A164 802E88E4 03E00008 */  jr        $ra
/* 10A168 802E88E8 27BD0018 */   addiu    $sp, $sp, 0x18
