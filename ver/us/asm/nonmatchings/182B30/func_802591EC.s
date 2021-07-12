.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029D3A0
.word L80259300_187BE0, L80259484_187D64, L80259484_187D64, L8025931C_187BFC, L80259338_187C18, L80259354_187C34, L80259370_187C50, L8025938C_187C6C, L802593A8_187C88, L802593C4_187CA4, L802593E0_187CC0, L80259484_187D64, L802593FC_187CDC, L8025941C_187CFC, L80259440_187D20, L80259450_187D30, L80259470_187D50, 0

.section .text

glabel func_802591EC
/* 187ACC 802591EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 187AD0 802591F0 00A0482D */  daddu     $t1, $a1, $zero
/* 187AD4 802591F4 00C0502D */  daddu     $t2, $a2, $zero
/* 187AD8 802591F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 187ADC 802591FC 8D250000 */  lw        $a1, ($t1)
/* 187AE0 80259200 8FA80030 */  lw        $t0, 0x30($sp)
/* 187AE4 80259204 30A20002 */  andi      $v0, $a1, 2
/* 187AE8 80259208 10400033 */  beqz      $v0, .L802592D8
/* 187AEC 8025920C 00E0582D */   daddu    $t3, $a3, $zero
/* 187AF0 80259210 240600FF */  addiu     $a2, $zero, 0xff
/* 187AF4 80259214 85230098 */  lh        $v1, 0x98($t1)
/* 187AF8 80259218 0066102A */  slt       $v0, $v1, $a2
/* 187AFC 8025921C 10400003 */  beqz      $v0, .L8025922C
/* 187B00 80259220 0000402D */   daddu    $t0, $zero, $zero
/* 187B04 80259224 3C088000 */  lui       $t0, 0x8000
/* 187B08 80259228 0060302D */  daddu     $a2, $v1, $zero
.L8025922C:
/* 187B0C 8025922C 30A20100 */  andi      $v0, $a1, 0x100
/* 187B10 80259230 1040000C */  beqz      $v0, .L80259264
/* 187B14 80259234 3C038080 */   lui      $v1, 0x8080
/* 187B18 80259238 34638081 */  ori       $v1, $v1, 0x8081
/* 187B1C 8025923C 00061100 */  sll       $v0, $a2, 4
/* 187B20 80259240 00461023 */  subu      $v0, $v0, $a2
/* 187B24 80259244 000210C0 */  sll       $v0, $v0, 3
/* 187B28 80259248 00430018 */  mult      $v0, $v1
/* 187B2C 8025924C 3C088000 */  lui       $t0, 0x8000
/* 187B30 80259250 00006010 */  mfhi      $t4
/* 187B34 80259254 01821821 */  addu      $v1, $t4, $v0
/* 187B38 80259258 000319C3 */  sra       $v1, $v1, 7
/* 187B3C 8025925C 000217C3 */  sra       $v0, $v0, 0x1f
/* 187B40 80259260 00623023 */  subu      $a2, $v1, $v0
.L80259264:
/* 187B44 80259264 1480000D */  bnez      $a0, .L8025929C
/* 187B48 80259268 240200FF */   addiu    $v0, $zero, 0xff
/* 187B4C 8025926C 14C20005 */  bne       $a2, $v0, .L80259284
/* 187B50 80259270 AFAB0010 */   sw       $t3, 0x10($sp)
/* 187B54 80259274 0000202D */  daddu     $a0, $zero, $zero
/* 187B58 80259278 0140282D */  daddu     $a1, $t2, $zero
/* 187B5C 8025927C 080964A3 */  j         .L8025928C
/* 187B60 80259280 0080302D */   daddu    $a2, $a0, $zero
.L80259284:
/* 187B64 80259284 0100202D */  daddu     $a0, $t0, $zero
/* 187B68 80259288 0140282D */  daddu     $a1, $t2, $zero
.L8025928C:
/* 187B6C 8025928C 0C0B7710 */  jal       spr_draw_player_sprite
/* 187B70 80259290 0000382D */   daddu    $a3, $zero, $zero
/* 187B74 80259294 08096522 */  j         .L80259488
/* 187B78 80259298 0000102D */   daddu    $v0, $zero, $zero
.L8025929C:
/* 187B7C 8025929C 14C20006 */  bne       $a2, $v0, .L802592B8
/* 187B80 802592A0 0140282D */   daddu    $a1, $t2, $zero
/* 187B84 802592A4 0000302D */  daddu     $a2, $zero, $zero
/* 187B88 802592A8 AFAB0010 */  sw        $t3, 0x10($sp)
/* 187B8C 802592AC 8D240084 */  lw        $a0, 0x84($t1)
/* 187B90 802592B0 080964B2 */  j         .L802592C8
/* 187B94 802592B4 00C0382D */   daddu    $a3, $a2, $zero
.L802592B8:
/* 187B98 802592B8 8D240084 */  lw        $a0, 0x84($t1)
/* 187B9C 802592BC 0000382D */  daddu     $a3, $zero, $zero
/* 187BA0 802592C0 AFAB0010 */  sw        $t3, 0x10($sp)
/* 187BA4 802592C4 00882025 */  or        $a0, $a0, $t0
.L802592C8:
/* 187BA8 802592C8 0C0B78F6 */  jal       spr_draw_npc_sprite
/* 187BAC 802592CC 00000000 */   nop
/* 187BB0 802592D0 08096522 */  j         .L80259488
/* 187BB4 802592D4 0000102D */   daddu    $v0, $zero, $zero
.L802592D8:
/* 187BB8 802592D8 8D2200C0 */  lw        $v0, 0xc0($t1)
/* 187BBC 802592DC 804306C0 */  lb        $v1, 0x6c0($v0)
/* 187BC0 802592E0 2C620011 */  sltiu     $v0, $v1, 0x11
/* 187BC4 802592E4 10400067 */  beqz      $v0, L80259484_187D64
/* 187BC8 802592E8 00031080 */   sll      $v0, $v1, 2
/* 187BCC 802592EC 3C01802A */  lui       $at, %hi(jtbl_8029D3A0)
/* 187BD0 802592F0 00220821 */  addu      $at, $at, $v0
/* 187BD4 802592F4 8C22D3A0 */  lw        $v0, %lo(jtbl_8029D3A0)($at)
/* 187BD8 802592F8 00400008 */  jr        $v0
/* 187BDC 802592FC 00000000 */   nop
glabel L80259300_187BE0
/* 187BE0 80259300 AFA80010 */  sw        $t0, 0x10($sp)
/* 187BE4 80259304 0120282D */  daddu     $a1, $t1, $zero
/* 187BE8 80259308 0140302D */  daddu     $a2, $t2, $zero
/* 187BEC 8025930C 0C096692 */  jal       func_80259A48
/* 187BF0 80259310 0160382D */   daddu    $a3, $t3, $zero
/* 187BF4 80259314 08096522 */  j         .L80259488
/* 187BF8 80259318 0000102D */   daddu    $v0, $zero, $zero
glabel L8025931C_187BFC
/* 187BFC 8025931C AFA80010 */  sw        $t0, 0x10($sp)
/* 187C00 80259320 0120282D */  daddu     $a1, $t1, $zero
/* 187C04 80259324 0140302D */  daddu     $a2, $t2, $zero
/* 187C08 80259328 0C0966AB */  jal       func_80259AAC
/* 187C0C 8025932C 0160382D */   daddu    $a3, $t3, $zero
/* 187C10 80259330 08096522 */  j         .L80259488
/* 187C14 80259334 0000102D */   daddu    $v0, $zero, $zero
glabel L80259338_187C18
/* 187C18 80259338 AFA80010 */  sw        $t0, 0x10($sp)
/* 187C1C 8025933C 0120282D */  daddu     $a1, $t1, $zero
/* 187C20 80259340 0140302D */  daddu     $a2, $t2, $zero
/* 187C24 80259344 0C096767 */  jal       func_80259D9C
/* 187C28 80259348 0160382D */   daddu    $a3, $t3, $zero
/* 187C2C 8025934C 08096522 */  j         .L80259488
/* 187C30 80259350 0000102D */   daddu    $v0, $zero, $zero
glabel L80259354_187C34
/* 187C34 80259354 AFA80010 */  sw        $t0, 0x10($sp)
/* 187C38 80259358 0120282D */  daddu     $a1, $t1, $zero
/* 187C3C 8025935C 0140302D */  daddu     $a2, $t2, $zero
/* 187C40 80259360 0C0968B1 */  jal       func_8025A2C4
/* 187C44 80259364 0160382D */   daddu    $a3, $t3, $zero
/* 187C48 80259368 08096522 */  j         .L80259488
/* 187C4C 8025936C 0000102D */   daddu    $v0, $zero, $zero
glabel L80259370_187C50
/* 187C50 80259370 AFA80010 */  sw        $t0, 0x10($sp)
/* 187C54 80259374 0120282D */  daddu     $a1, $t1, $zero
/* 187C58 80259378 0140302D */  daddu     $a2, $t2, $zero
/* 187C5C 8025937C 0C096943 */  jal       func_8025A50C
/* 187C60 80259380 0160382D */   daddu    $a3, $t3, $zero
/* 187C64 80259384 08096522 */  j         .L80259488
/* 187C68 80259388 0000102D */   daddu    $v0, $zero, $zero
glabel L8025938C_187C6C
/* 187C6C 8025938C AFA80010 */  sw        $t0, 0x10($sp)
/* 187C70 80259390 0120282D */  daddu     $a1, $t1, $zero
/* 187C74 80259394 0140302D */  daddu     $a2, $t2, $zero
/* 187C78 80259398 0C0969D3 */  jal       func_8025A74C
/* 187C7C 8025939C 0160382D */   daddu    $a3, $t3, $zero
/* 187C80 802593A0 08096522 */  j         .L80259488
/* 187C84 802593A4 0000102D */   daddu    $v0, $zero, $zero
glabel L802593A8_187C88
/* 187C88 802593A8 AFA80010 */  sw        $t0, 0x10($sp)
/* 187C8C 802593AC 0120282D */  daddu     $a1, $t1, $zero
/* 187C90 802593B0 0140302D */  daddu     $a2, $t2, $zero
/* 187C94 802593B4 0C096AA0 */  jal       func_8025AA80
/* 187C98 802593B8 0160382D */   daddu    $a3, $t3, $zero
/* 187C9C 802593BC 08096522 */  j         .L80259488
/* 187CA0 802593C0 0000102D */   daddu    $v0, $zero, $zero
glabel L802593C4_187CA4
/* 187CA4 802593C4 AFA80010 */  sw        $t0, 0x10($sp)
/* 187CA8 802593C8 0120282D */  daddu     $a1, $t1, $zero
/* 187CAC 802593CC 0140302D */  daddu     $a2, $t2, $zero
/* 187CB0 802593D0 0C096B64 */  jal       func_8025AD90
/* 187CB4 802593D4 0160382D */   daddu    $a3, $t3, $zero
/* 187CB8 802593D8 08096522 */  j         .L80259488
/* 187CBC 802593DC 0000102D */   daddu    $v0, $zero, $zero
glabel L802593E0_187CC0
/* 187CC0 802593E0 AFA80010 */  sw        $t0, 0x10($sp)
/* 187CC4 802593E4 0120282D */  daddu     $a1, $t1, $zero
/* 187CC8 802593E8 0140302D */  daddu     $a2, $t2, $zero
/* 187CCC 802593EC 0C096C6A */  jal       func_8025B1A8
/* 187CD0 802593F0 0160382D */   daddu    $a3, $t3, $zero
/* 187CD4 802593F4 08096522 */  j         .L80259488
/* 187CD8 802593F8 0000102D */   daddu    $v0, $zero, $zero
glabel L802593FC_187CDC
/* 187CDC 802593FC 0120282D */  daddu     $a1, $t1, $zero
/* 187CE0 80259400 0140302D */  daddu     $a2, $t2, $zero
/* 187CE4 80259404 0160382D */  daddu     $a3, $t3, $zero
/* 187CE8 80259408 AFA80010 */  sw        $t0, 0x10($sp)
/* 187CEC 8025940C 0C096D70 */  jal       func_8025B5C0
/* 187CF0 80259410 AFA00014 */   sw       $zero, 0x14($sp)
/* 187CF4 80259414 08096522 */  j         .L80259488
/* 187CF8 80259418 0000102D */   daddu    $v0, $zero, $zero
glabel L8025941C_187CFC
/* 187CFC 8025941C 0120282D */  daddu     $a1, $t1, $zero
/* 187D00 80259420 0140302D */  daddu     $a2, $t2, $zero
/* 187D04 80259424 0160382D */  daddu     $a3, $t3, $zero
/* 187D08 80259428 24020001 */  addiu     $v0, $zero, 1
/* 187D0C 8025942C AFA80010 */  sw        $t0, 0x10($sp)
/* 187D10 80259430 0C096D70 */  jal       func_8025B5C0
/* 187D14 80259434 AFA20014 */   sw       $v0, 0x14($sp)
/* 187D18 80259438 08096522 */  j         .L80259488
/* 187D1C 8025943C 0000102D */   daddu    $v0, $zero, $zero
glabel L80259440_187D20
/* 187D20 80259440 0120282D */  daddu     $a1, $t1, $zero
/* 187D24 80259444 0140302D */  daddu     $a2, $t2, $zero
/* 187D28 80259448 08096517 */  j         .L8025945C
/* 187D2C 8025944C 0000382D */   daddu    $a3, $zero, $zero
glabel L80259450_187D30
/* 187D30 80259450 0120282D */  daddu     $a1, $t1, $zero
/* 187D34 80259454 0140302D */  daddu     $a2, $t2, $zero
/* 187D38 80259458 24070001 */  addiu     $a3, $zero, 1
.L8025945C:
/* 187D3C 8025945C AFAB0010 */  sw        $t3, 0x10($sp)
/* 187D40 80259460 0C096EA8 */  jal       func_8025BAA0
/* 187D44 80259464 AFA80014 */   sw       $t0, 0x14($sp)
/* 187D48 80259468 08096522 */  j         .L80259488
/* 187D4C 8025946C 0000102D */   daddu    $v0, $zero, $zero
glabel L80259470_187D50
/* 187D50 80259470 AFA80010 */  sw        $t0, 0x10($sp)
/* 187D54 80259474 0120282D */  daddu     $a1, $t1, $zero
/* 187D58 80259478 0140302D */  daddu     $a2, $t2, $zero
/* 187D5C 8025947C 0C097048 */  jal       func_8025C120
/* 187D60 80259480 0160382D */   daddu    $a3, $t3, $zero
glabel L80259484_187D64
/* 187D64 80259484 0000102D */  daddu     $v0, $zero, $zero
.L80259488:
/* 187D68 80259488 8FBF0018 */  lw        $ra, 0x18($sp)
/* 187D6C 8025948C 03E00008 */  jr        $ra
/* 187D70 80259490 27BD0020 */   addiu    $sp, $sp, 0x20
