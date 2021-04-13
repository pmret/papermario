.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6198_E241D8
/* E241D8 802B6198 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E241DC 802B619C AFB00010 */  sw        $s0, 0x10($sp)
/* E241E0 802B61A0 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E241E4 802B61A4 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E241E8 802B61A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* E241EC 802B61AC AFB10014 */  sw        $s1, 0x14($sp)
/* E241F0 802B61B0 8E020000 */  lw        $v0, ($s0)
/* E241F4 802B61B4 04410012 */  bgez      $v0, .L802B6200
/* E241F8 802B61B8 3C118000 */   lui      $s1, 0x8000
/* E241FC 802B61BC 3C028016 */  lui       $v0, %hi(gCollisionStatus)
/* E24200 802B61C0 2442A550 */  addiu     $v0, $v0, %lo(gCollisionStatus)
/* E24204 802B61C4 0C04417A */  jal       get_entity_by_index
/* E24208 802B61C8 84440002 */   lh       $a0, 2($v0)
/* E2420C 802B61CC C4400048 */  lwc1      $f0, 0x48($v0)
/* E24210 802B61D0 C4420050 */  lwc1      $f2, 0x50($v0)
/* E24214 802B61D4 3C018011 */  lui       $at, %hi(D_8010C960)
/* E24218 802B61D8 E420C960 */  swc1      $f0, %lo(D_8010C960)($at)
/* E2421C 802B61DC 3C018011 */  lui       $at, %hi(D_8010C97C)
/* E24220 802B61E0 E422C97C */  swc1      $f2, %lo(D_8010C97C)($at)
/* E24224 802B61E4 0C0AD800 */  jal       func_802B6000_E24040
/* E24228 802B61E8 00000000 */   nop
/* E2422C 802B61EC 8E020000 */  lw        $v0, ($s0)
/* E24230 802B61F0 3C030088 */  lui       $v1, 0x88
/* E24234 802B61F4 00431025 */  or        $v0, $v0, $v1
/* E24238 802B61F8 0C03805E */  jal       disable_player_input
/* E2423C 802B61FC AE020000 */   sw       $v0, ($s0)
.L802B6200:
/* E24240 802B6200 960200C0 */  lhu       $v0, 0xc0($s0)
/* E24244 802B6204 820300B6 */  lb        $v1, 0xb6($s0)
/* E24248 802B6208 24420001 */  addiu     $v0, $v0, 1
/* E2424C 802B620C A60200C0 */  sh        $v0, 0xc0($s0)
/* E24250 802B6210 24020001 */  addiu     $v0, $zero, 1
/* E24254 802B6214 1462001A */  bne       $v1, $v0, .L802B6280
/* E24258 802B6218 00000000 */   nop
/* E2425C 802B621C 8E050000 */  lw        $a1, ($s0)
/* E24260 802B6220 00B11024 */  and       $v0, $a1, $s1
/* E24264 802B6224 10400013 */  beqz      $v0, .L802B6274
/* E24268 802B6228 3C037FFF */   lui      $v1, 0x7fff
/* E2426C 802B622C 3463FFF5 */  ori       $v1, $v1, 0xfff5
/* E24270 802B6230 3C040006 */  lui       $a0, 6
/* E24274 802B6234 3484000A */  ori       $a0, $a0, 0xa
/* E24278 802B6238 00A31824 */  and       $v1, $a1, $v1
/* E2427C 802B623C 8E020004 */  lw        $v0, 4($s0)
/* E24280 802B6240 34630004 */  ori       $v1, $v1, 4
/* E24284 802B6244 30420003 */  andi      $v0, $v0, 3
/* E24288 802B6248 14400003 */  bnez      $v0, .L802B6258
/* E2428C 802B624C AE030000 */   sw       $v1, ($s0)
/* E24290 802B6250 3C040001 */  lui       $a0, 1
/* E24294 802B6254 34840008 */  ori       $a0, $a0, 8
.L802B6258:
/* E24298 802B6258 0C037FBF */  jal       func_800DFEFC
/* E2429C 802B625C 00000000 */   nop
/* E242A0 802B6260 3C03800B */  lui       $v1, %hi(gCameras)
/* E242A4 802B6264 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E242A8 802B6268 94620002 */  lhu       $v0, 2($v1)
/* E242AC 802B626C 34420001 */  ori       $v0, $v0, 1
/* E242B0 802B6270 A4620002 */  sh        $v0, 2($v1)
.L802B6274:
/* E242B4 802B6274 920200B6 */  lbu       $v0, 0xb6($s0)
/* E242B8 802B6278 24420001 */  addiu     $v0, $v0, 1
/* E242BC 802B627C A20200B6 */  sb        $v0, 0xb6($s0)
.L802B6280:
/* E242C0 802B6280 8FBF0018 */  lw        $ra, 0x18($sp)
/* E242C4 802B6284 8FB10014 */  lw        $s1, 0x14($sp)
/* E242C8 802B6288 8FB00010 */  lw        $s0, 0x10($sp)
/* E242CC 802B628C 03E00008 */  jr        $ra
/* E242D0 802B6290 27BD0020 */   addiu    $sp, $sp, 0x20
