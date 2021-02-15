.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6198_E24768
/* E24768 802B6198 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2476C 802B619C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* E24770 802B61A0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* E24774 802B61A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* E24778 802B61A8 8C620004 */  lw        $v0, 4($v1)
/* E2477C 802B61AC 30422000 */  andi      $v0, $v0, 0x2000
/* E24780 802B61B0 14400013 */  bnez      $v0, .L802B6200
/* E24784 802B61B4 00000000 */   nop
/* E24788 802B61B8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E2478C 802B61BC 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E24790 802B61C0 9062007E */  lbu       $v0, 0x7e($v1)
/* E24794 802B61C4 30420010 */  andi      $v0, $v0, 0x10
/* E24798 802B61C8 14400009 */  bnez      $v0, .L802B61F0
/* E2479C 802B61CC 3C04000D */   lui      $a0, 0xd
/* E247A0 802B61D0 90620080 */  lbu       $v0, 0x80($v1)
/* E247A4 802B61D4 00021080 */  sll       $v0, $v0, 2
/* E247A8 802B61D8 3C04802B */  lui       $a0, %hi(D_802B6300_E248D0)
/* E247AC 802B61DC 00822021 */  addu      $a0, $a0, $v0
/* E247B0 802B61E0 0C037FBF */  jal       func_800DFEFC
/* E247B4 802B61E4 8C846300 */   lw       $a0, %lo(D_802B6300_E248D0)($a0)
/* E247B8 802B61E8 080AD889 */  j         .L802B6224
/* E247BC 802B61EC 00000000 */   nop
.L802B61F0:
/* E247C0 802B61F0 0C037FBF */  jal       func_800DFEFC
/* E247C4 802B61F4 3484000D */   ori      $a0, $a0, 0xd
/* E247C8 802B61F8 080AD889 */  j         .L802B6224
/* E247CC 802B61FC 00000000 */   nop
.L802B6200:
/* E247D0 802B6200 8063000C */  lb        $v1, 0xc($v1)
/* E247D4 802B6204 00031040 */  sll       $v0, $v1, 1
/* E247D8 802B6208 00431021 */  addu      $v0, $v0, $v1
/* E247DC 802B620C 000210C0 */  sll       $v0, $v0, 3
/* E247E0 802B6210 3C04800F */  lui       $a0, %hi(D_800F7C20)
/* E247E4 802B6214 00822021 */  addu      $a0, $a0, $v0
/* E247E8 802B6218 8C847C20 */  lw        $a0, %lo(D_800F7C20)($a0)
/* E247EC 802B621C 0C0398DB */  jal       func_800E636C
/* E247F0 802B6220 00000000 */   nop
.L802B6224:
/* E247F4 802B6224 8FBF0010 */  lw        $ra, 0x10($sp)
/* E247F8 802B6228 03E00008 */  jr        $ra
/* E247FC 802B622C 27BD0018 */   addiu    $sp, $sp, 0x18
