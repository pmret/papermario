.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_message
/* 16A1DC 8024997C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 16A1E0 80249980 8FA2004C */  lw        $v0, 0x4c($sp)
/* 16A1E4 80249984 AFB5002C */  sw        $s5, 0x2c($sp)
/* 16A1E8 80249988 8FB50048 */  lw        $s5, 0x48($sp)
/* 16A1EC 8024998C AFB00018 */  sw        $s0, 0x18($sp)
/* 16A1F0 80249990 0080802D */  daddu     $s0, $a0, $zero
/* 16A1F4 80249994 AFB1001C */  sw        $s1, 0x1c($sp)
/* 16A1F8 80249998 00A0882D */  daddu     $s1, $a1, $zero
/* 16A1FC 8024999C AFB20020 */  sw        $s2, 0x20($sp)
/* 16A200 802499A0 00C0902D */  daddu     $s2, $a2, $zero
/* 16A204 802499A4 AFBF0034 */  sw        $ra, 0x34($sp)
/* 16A208 802499A8 AFB60030 */  sw        $s6, 0x30($sp)
/* 16A20C 802499AC AFB40028 */  sw        $s4, 0x28($sp)
/* 16A210 802499B0 AFB30024 */  sw        $s3, 0x24($sp)
/* 16A214 802499B4 000298C2 */  srl       $s3, $v0, 3
/* 16A218 802499B8 30540001 */  andi      $s4, $v0, 1
/* 16A21C 802499BC 24020001 */  addiu     $v0, $zero, 1
/* 16A220 802499C0 16820002 */  bne       $s4, $v0, .L802499CC
/* 16A224 802499C4 32730001 */   andi     $s3, $s3, 1
/* 16A228 802499C8 2652FFFE */  addiu     $s2, $s2, -2
.L802499CC:
/* 16A22C 802499CC 2E020100 */  sltiu     $v0, $s0, 0x100
/* 16A230 802499D0 10400013 */  beqz      $v0, .L80249A20
/* 16A234 802499D4 2602FF5E */   addiu    $v0, $s0, -0xa2
/* 16A238 802499D8 2C42004E */  sltiu     $v0, $v0, 0x4e
/* 16A23C 802499DC 1440000A */  bnez      $v0, .L80249A08
/* 16A240 802499E0 2A0200C6 */   slti     $v0, $s0, 0xc6
/* 16A244 802499E4 0200202D */  daddu     $a0, $s0, $zero
/* 16A248 802499E8 0220282D */  daddu     $a1, $s1, $zero
/* 16A24C 802499EC 0240302D */  daddu     $a2, $s2, $zero
/* 16A250 802499F0 0280382D */  daddu     $a3, $s4, $zero
/* 16A254 802499F4 AFB50010 */  sw        $s5, 0x10($sp)
/* 16A258 802499F8 0C0924E0 */  jal       filemenu_draw_char
/* 16A25C 802499FC AFB30014 */   sw       $s3, 0x14($sp)
/* 16A260 80249A00 0809269F */  j         .L80249A7C
/* 16A264 80249A04 00000000 */   nop
.L80249A08:
/* 16A268 80249A08 14400005 */  bnez      $v0, .L80249A20
/* 16A26C 80249A0C 2602FF3A */   addiu    $v0, $s0, -0xc6
/* 16A270 80249A10 00021080 */  sll       $v0, $v0, 2
/* 16A274 80249A14 3C108025 */  lui       $s0, %hi(D_8024B74C)
/* 16A278 80249A18 02028021 */  addu      $s0, $s0, $v0
/* 16A27C 80249A1C 8E10B74C */  lw        $s0, %lo(D_8024B74C)($s0)
.L80249A20:
/* 16A280 80249A20 06010016 */  bgez      $s0, .L80249A7C
/* 16A284 80249A24 240400F3 */   addiu    $a0, $zero, 0xf3
/* 16A288 80249A28 0220282D */  daddu     $a1, $s1, $zero
/* 16A28C 80249A2C 0240302D */  daddu     $a2, $s2, $zero
/* 16A290 80249A30 0280382D */  daddu     $a3, $s4, $zero
/* 16A294 80249A34 AFB50010 */  sw        $s5, 0x10($sp)
/* 16A298 80249A38 0C0924E0 */  jal       filemenu_draw_char
/* 16A29C 80249A3C AFB30014 */   sw       $s3, 0x14($sp)
/* 16A2A0 80249A40 92030000 */  lbu       $v1, ($s0)
/* 16A2A4 80249A44 240200FD */  addiu     $v0, $zero, 0xfd
/* 16A2A8 80249A48 1062000C */  beq       $v1, $v0, .L80249A7C
/* 16A2AC 80249A4C 0040B02D */   daddu    $s6, $v0, $zero
.L80249A50:
/* 16A2B0 80249A50 0220282D */  daddu     $a1, $s1, $zero
/* 16A2B4 80249A54 0240302D */  daddu     $a2, $s2, $zero
/* 16A2B8 80249A58 0280382D */  daddu     $a3, $s4, $zero
/* 16A2BC 80249A5C 92040000 */  lbu       $a0, ($s0)
/* 16A2C0 80249A60 26100001 */  addiu     $s0, $s0, 1
/* 16A2C4 80249A64 AFB50010 */  sw        $s5, 0x10($sp)
/* 16A2C8 80249A68 0C0924E0 */  jal       filemenu_draw_char
/* 16A2CC 80249A6C AFB30014 */   sw       $s3, 0x14($sp)
/* 16A2D0 80249A70 92030000 */  lbu       $v1, ($s0)
/* 16A2D4 80249A74 1476FFF6 */  bne       $v1, $s6, .L80249A50
/* 16A2D8 80249A78 02228821 */   addu     $s1, $s1, $v0
.L80249A7C:
/* 16A2DC 80249A7C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 16A2E0 80249A80 8FB60030 */  lw        $s6, 0x30($sp)
/* 16A2E4 80249A84 8FB5002C */  lw        $s5, 0x2c($sp)
/* 16A2E8 80249A88 8FB40028 */  lw        $s4, 0x28($sp)
/* 16A2EC 80249A8C 8FB30024 */  lw        $s3, 0x24($sp)
/* 16A2F0 80249A90 8FB20020 */  lw        $s2, 0x20($sp)
/* 16A2F4 80249A94 8FB1001C */  lw        $s1, 0x1c($sp)
/* 16A2F8 80249A98 8FB00018 */  lw        $s0, 0x18($sp)
/* 16A2FC 80249A9C 03E00008 */  jr        $ra
/* 16A300 80249AA0 27BD0038 */   addiu    $sp, $sp, 0x38
