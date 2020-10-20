.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240280_CF0BC0
/* CF0BC0 80240280 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF0BC4 80240284 AFB00010 */  sw        $s0, 0x10($sp)
/* CF0BC8 80240288 0080802D */  daddu     $s0, $a0, $zero
/* CF0BCC 8024028C AFBF0014 */  sw        $ra, 0x14($sp)
/* CF0BD0 80240290 8E0300A8 */  lw        $v1, 0xa8($s0)
/* CF0BD4 80240294 8E020088 */  lw        $v0, 0x88($s0)
/* CF0BD8 80240298 00621821 */  addu      $v1, $v1, $v0
/* CF0BDC 8024029C 04610004 */  bgez      $v1, .L802402B0
/* CF0BE0 802402A0 AE0300A8 */   sw       $v1, 0xa8($s0)
/* CF0BE4 802402A4 3C020002 */  lui       $v0, 2
/* CF0BE8 802402A8 080900B0 */  j         .L802402C0
/* CF0BEC 802402AC 00621021 */   addu     $v0, $v1, $v0
.L802402B0:
/* CF0BF0 802402B0 3C040002 */  lui       $a0, 2
/* CF0BF4 802402B4 0083102A */  slt       $v0, $a0, $v1
/* CF0BF8 802402B8 10400002 */  beqz      $v0, .L802402C4
/* CF0BFC 802402BC 00641023 */   subu     $v0, $v1, $a0
.L802402C0:
/* CF0C00 802402C0 AE0200A8 */  sw        $v0, 0xa8($s0)
.L802402C4:
/* CF0C04 802402C4 8E0300AC */  lw        $v1, 0xac($s0)
/* CF0C08 802402C8 8E02008C */  lw        $v0, 0x8c($s0)
/* CF0C0C 802402CC 00621821 */  addu      $v1, $v1, $v0
/* CF0C10 802402D0 04610004 */  bgez      $v1, .L802402E4
/* CF0C14 802402D4 AE0300AC */   sw       $v1, 0xac($s0)
/* CF0C18 802402D8 3C020002 */  lui       $v0, 2
/* CF0C1C 802402DC 080900BD */  j         .L802402F4
/* CF0C20 802402E0 00621021 */   addu     $v0, $v1, $v0
.L802402E4:
/* CF0C24 802402E4 3C040002 */  lui       $a0, 2
/* CF0C28 802402E8 0083102A */  slt       $v0, $a0, $v1
/* CF0C2C 802402EC 10400002 */  beqz      $v0, .L802402F8
/* CF0C30 802402F0 00641023 */   subu     $v0, $v1, $a0
.L802402F4:
/* CF0C34 802402F4 AE0200AC */  sw        $v0, 0xac($s0)
.L802402F8:
/* CF0C38 802402F8 8E0300B0 */  lw        $v1, 0xb0($s0)
/* CF0C3C 802402FC 8E020090 */  lw        $v0, 0x90($s0)
/* CF0C40 80240300 00621821 */  addu      $v1, $v1, $v0
/* CF0C44 80240304 04610004 */  bgez      $v1, .L80240318
/* CF0C48 80240308 AE0300B0 */   sw       $v1, 0xb0($s0)
/* CF0C4C 8024030C 3C020002 */  lui       $v0, 2
/* CF0C50 80240310 080900CA */  j         .L80240328
/* CF0C54 80240314 00621021 */   addu     $v0, $v1, $v0
.L80240318:
/* CF0C58 80240318 3C040002 */  lui       $a0, 2
/* CF0C5C 8024031C 0083102A */  slt       $v0, $a0, $v1
/* CF0C60 80240320 10400002 */  beqz      $v0, .L8024032C
/* CF0C64 80240324 00641023 */   subu     $v0, $v1, $a0
.L80240328:
/* CF0C68 80240328 AE0200B0 */  sw        $v0, 0xb0($s0)
.L8024032C:
/* CF0C6C 8024032C 8E0300B4 */  lw        $v1, 0xb4($s0)
/* CF0C70 80240330 8E020094 */  lw        $v0, 0x94($s0)
/* CF0C74 80240334 00621821 */  addu      $v1, $v1, $v0
/* CF0C78 80240338 04610004 */  bgez      $v1, .L8024034C
/* CF0C7C 8024033C AE0300B4 */   sw       $v1, 0xb4($s0)
/* CF0C80 80240340 3C020002 */  lui       $v0, 2
/* CF0C84 80240344 080900D7 */  j         .L8024035C
/* CF0C88 80240348 00621021 */   addu     $v0, $v1, $v0
.L8024034C:
/* CF0C8C 8024034C 3C040002 */  lui       $a0, 2
/* CF0C90 80240350 0083102A */  slt       $v0, $a0, $v1
/* CF0C94 80240354 10400002 */  beqz      $v0, .L80240360
/* CF0C98 80240358 00641023 */   subu     $v0, $v1, $a0
.L8024035C:
/* CF0C9C 8024035C AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240360:
/* CF0CA0 80240360 8E040084 */  lw        $a0, 0x84($s0)
/* CF0CA4 80240364 0C046F07 */  jal       set_main_pan_u
/* CF0CA8 80240368 8E0500A8 */   lw       $a1, 0xa8($s0)
/* CF0CAC 8024036C 8E040084 */  lw        $a0, 0x84($s0)
/* CF0CB0 80240370 0C046F0D */  jal       set_main_pan_v
/* CF0CB4 80240374 8E0500AC */   lw       $a1, 0xac($s0)
/* CF0CB8 80240378 8E040084 */  lw        $a0, 0x84($s0)
/* CF0CBC 8024037C 0C046F13 */  jal       set_aux_pan_u
/* CF0CC0 80240380 8E0500B0 */   lw       $a1, 0xb0($s0)
/* CF0CC4 80240384 8E040084 */  lw        $a0, 0x84($s0)
/* CF0CC8 80240388 0C046F19 */  jal       set_aux_pan_v
/* CF0CCC 8024038C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* CF0CD0 80240390 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF0CD4 80240394 8FB00010 */  lw        $s0, 0x10($sp)
/* CF0CD8 80240398 0000102D */  daddu     $v0, $zero, $zero
/* CF0CDC 8024039C 03E00008 */  jr        $ra
/* CF0CE0 802403A0 27BD0018 */   addiu    $sp, $sp, 0x18
