.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261164
/* 18FA44 80261164 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18FA48 80261168 AFB00010 */  sw        $s0, 0x10($sp)
/* 18FA4C 8026116C 0080802D */  daddu     $s0, $a0, $zero
/* 18FA50 80261170 10A00004 */  beqz      $a1, .L80261184
/* 18FA54 80261174 AFBF0014 */   sw       $ra, 0x14($sp)
/* 18FA58 80261178 24020014 */  addiu     $v0, $zero, 0x14
/* 18FA5C 8026117C 0C093980 */  jal       unfreeze_cam
/* 18FA60 80261180 AE020070 */   sw       $v0, 0x70($s0)
.L80261184:
/* 18FA64 80261184 0000202D */  daddu     $a0, $zero, $zero
/* 18FA68 80261188 0080282D */  daddu     $a1, $a0, $zero
/* 18FA6C 8026118C 8E020070 */  lw        $v0, 0x70($s0)
/* 18FA70 80261190 0080302D */  daddu     $a2, $a0, $zero
/* 18FA74 80261194 00023840 */  sll       $a3, $v0, 1
/* 18FA78 80261198 00E23821 */  addu      $a3, $a3, $v0
/* 18FA7C 8026119C 00073880 */  sll       $a3, $a3, 2
/* 18FA80 802611A0 0C046F97 */  jal       set_background_color_blend
/* 18FA84 802611A4 30E700FC */   andi     $a3, $a3, 0xfc
/* 18FA88 802611A8 8E020070 */  lw        $v0, 0x70($s0)
/* 18FA8C 802611AC 2442FFFF */  addiu     $v0, $v0, -1
/* 18FA90 802611B0 10400003 */  beqz      $v0, .L802611C0
/* 18FA94 802611B4 AE020070 */   sw       $v0, 0x70($s0)
/* 18FA98 802611B8 08098476 */  j         .L802611D8
/* 18FA9C 802611BC 0000102D */   daddu    $v0, $zero, $zero
.L802611C0:
/* 18FAA0 802611C0 0000202D */  daddu     $a0, $zero, $zero
/* 18FAA4 802611C4 0080282D */  daddu     $a1, $a0, $zero
/* 18FAA8 802611C8 0080302D */  daddu     $a2, $a0, $zero
/* 18FAAC 802611CC 0C046F97 */  jal       set_background_color_blend
/* 18FAB0 802611D0 0080382D */   daddu    $a3, $a0, $zero
/* 18FAB4 802611D4 24020002 */  addiu     $v0, $zero, 2
.L802611D8:
/* 18FAB8 802611D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 18FABC 802611DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 18FAC0 802611E0 03E00008 */  jr        $ra
/* 18FAC4 802611E4 27BD0018 */   addiu    $sp, $sp, 0x18
