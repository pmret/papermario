.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE3A4
/* 31F114 802BE3A4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 31F118 802BE3A8 AFB5005C */  sw        $s5, 0x5c($sp)
/* 31F11C 802BE3AC 0080A82D */  daddu     $s5, $a0, $zero
/* 31F120 802BE3B0 AFB20050 */  sw        $s2, 0x50($sp)
/* 31F124 802BE3B4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 31F128 802BE3B8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 31F12C 802BE3BC AFB00048 */  sw        $s0, 0x48($sp)
/* 31F130 802BE3C0 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 31F134 802BE3C4 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 31F138 802BE3C8 AFB60060 */  sw        $s6, 0x60($sp)
/* 31F13C 802BE3CC 3C168016 */  lui       $s6, 0x8016
/* 31F140 802BE3D0 26D6A550 */  addiu     $s6, $s6, -0x5ab0
/* 31F144 802BE3D4 AFB40058 */  sw        $s4, 0x58($sp)
/* 31F148 802BE3D8 3C148011 */  lui       $s4, %hi(D_8010EBB0)
/* 31F14C 802BE3DC 2694EBB0 */  addiu     $s4, $s4, %lo(D_8010EBB0)
/* 31F150 802BE3E0 AFBF0064 */  sw        $ra, 0x64($sp)
/* 31F154 802BE3E4 AFB30054 */  sw        $s3, 0x54($sp)
/* 31F158 802BE3E8 AFB1004C */  sw        $s1, 0x4c($sp)
/* 31F15C 802BE3EC F7B40068 */  sdc1      $f20, 0x68($sp)
/* 31F160 802BE3F0 8EB1014C */  lw        $s1, 0x14c($s5)
/* 31F164 802BE3F4 10A0000F */  beqz      $a1, .L802BE434
/* 31F168 802BE3F8 3C04FFBF */   lui      $a0, 0xffbf
/* 31F16C 802BE3FC 0C0AFE48 */  jal       func_802BF920
/* 31F170 802BE400 0220202D */   daddu    $a0, $s1, $zero
/* 31F174 802BE404 3C01802C */  lui       $at, 0x802c
/* 31F178 802BE408 AC20FEFC */  sw        $zero, -0x104($at)
/* 31F17C 802BE40C 3C01802C */  lui       $at, 0x802c
/* 31F180 802BE410 AC20FEF8 */  sw        $zero, -0x108($at)
/* 31F184 802BE414 3C01802C */  lui       $at, 0x802c
/* 31F188 802BE418 AC20FF00 */  sw        $zero, -0x100($at)
/* 31F18C 802BE41C 3C01802C */  lui       $at, 0x802c
/* 31F190 802BE420 AC20FF04 */  sw        $zero, -0xfc($at)
/* 31F194 802BE424 3C01802C */  lui       $at, 0x802c
/* 31F198 802BE428 AC20FF08 */  sw        $zero, -0xf8($at)
/* 31F19C 802BE42C AEA00070 */  sw        $zero, 0x70($s5)
/* 31F1A0 802BE430 3C04FFBF */  lui       $a0, 0xffbf
.L802BE434:
/* 31F1A4 802BE434 3484FFFF */  ori       $a0, $a0, 0xffff
/* 31F1A8 802BE438 8E020310 */  lw        $v0, 0x310($s0)
/* 31F1AC 802BE43C 8E430004 */  lw        $v1, 4($s2)
/* 31F1B0 802BE440 24420001 */  addiu     $v0, $v0, 1
/* 31F1B4 802BE444 00641824 */  and       $v1, $v1, $a0
/* 31F1B8 802BE448 AE020310 */  sw        $v0, 0x310($s0)
/* 31F1BC 802BE44C AE430004 */  sw        $v1, 4($s2)
/* 31F1C0 802BE450 8EA30070 */  lw        $v1, 0x70($s5)
/* 31F1C4 802BE454 2C62001A */  sltiu     $v0, $v1, 0x1a
/* 31F1C8 802BE458 10400425 */  beqz      $v0, .L802BF4F0
/* 31F1CC 802BE45C 00031080 */   sll      $v0, $v1, 2
/* 31F1D0 802BE460 3C01802C */  lui       $at, 0x802c
/* 31F1D4 802BE464 00220821 */  addu      $at, $at, $v0
/* 31F1D8 802BE468 8C22FE68 */  lw        $v0, -0x198($at)
/* 31F1DC 802BE46C 00400008 */  jr        $v0
/* 31F1E0 802BE470 00000000 */   nop      
/* 31F1E4 802BE474 3C138007 */  lui       $s3, %hi(gGameStatusPtr)
/* 31F1E8 802BE478 2673419C */  addiu     $s3, $s3, %lo(gGameStatusPtr)
/* 31F1EC 802BE47C 8E620000 */  lw        $v0, ($s3)
/* 31F1F0 802BE480 8042007D */  lb        $v0, 0x7d($v0)
/* 31F1F4 802BE484 14400012 */  bnez      $v0, .L802BE4D0
/* 31F1F8 802BE488 3C040008 */   lui      $a0, 8
/* 31F1FC 802BE48C 86C40012 */  lh        $a0, 0x12($s6)
/* 31F200 802BE490 0480000A */  bltz      $a0, .L802BE4BC
/* 31F204 802BE494 AFA40040 */   sw       $a0, 0x40($sp)
/* 31F208 802BE498 30824000 */  andi      $v0, $a0, 0x4000
/* 31F20C 802BE49C 14400415 */  bnez      $v0, .L802BF4F4
/* 31F210 802BE4A0 24020001 */   addiu    $v0, $zero, 1
/* 31F214 802BE4A4 0C016F6A */  jal       get_collider_type_by_id
/* 31F218 802BE4A8 00000000 */   nop      
/* 31F21C 802BE4AC 304200FF */  andi      $v0, $v0, 0xff
/* 31F220 802BE4B0 24030004 */  addiu     $v1, $zero, 4
/* 31F224 802BE4B4 10430003 */  beq       $v0, $v1, .L802BE4C4
/* 31F228 802BE4B8 AFA20040 */   sw       $v0, 0x40($sp)
.L802BE4BC:
/* 31F22C 802BE4BC 080AFD3D */  j         .L802BF4F4
/* 31F230 802BE4C0 24020001 */   addiu    $v0, $zero, 1
.L802BE4C4:
/* 31F234 802BE4C4 24020014 */  addiu     $v0, $zero, 0x14
/* 31F238 802BE4C8 080AFD3C */  j         .L802BF4F0
/* 31F23C 802BE4CC AEA20070 */   sw       $v0, 0x70($s5)
.L802BE4D0:
/* 31F240 802BE4D0 C622003C */  lwc1      $f2, 0x3c($s1)
/* 31F244 802BE4D4 3C014180 */  lui       $at, 0x4180
/* 31F248 802BE4D8 44810000 */  mtc1      $at, $f0
/* 31F24C 802BE4DC 3484000F */  ori       $a0, $a0, 0xf
/* 31F250 802BE4E0 46001000 */  add.s     $f0, $f2, $f0
/* 31F254 802BE4E4 24100001 */  addiu     $s0, $zero, 1
/* 31F258 802BE4E8 E6220064 */  swc1      $f2, 0x64($s1)
/* 31F25C 802BE4EC E640002C */  swc1      $f0, 0x2c($s2)
/* 31F260 802BE4F0 8E220000 */  lw        $v0, ($s1)
/* 31F264 802BE4F4 2403FDFF */  addiu     $v1, $zero, -0x201
/* 31F268 802BE4F8 3C01802C */  lui       $at, 0x802c
/* 31F26C 802BE4FC AC30FEEC */  sw        $s0, -0x114($at)
/* 31F270 802BE500 34420008 */  ori       $v0, $v0, 8
/* 31F274 802BE504 00431024 */  and       $v0, $v0, $v1
/* 31F278 802BE508 34420100 */  ori       $v0, $v0, 0x100
/* 31F27C 802BE50C 0C037FDE */  jal       func_800DFF78
/* 31F280 802BE510 AE220000 */   sw       $v0, ($s1)
/* 31F284 802BE514 0C038039 */  jal       disable_player_shadow
/* 31F288 802BE518 00000000 */   nop      
/* 31F28C 802BE51C 0C00EAFF */  jal       disable_npc_shadow
/* 31F290 802BE520 0220202D */   daddu    $a0, $s1, $zero
/* 31F294 802BE524 0220202D */  daddu     $a0, $s1, $zero
/* 31F298 802BE528 24050004 */  addiu     $a1, $zero, 4
/* 31F29C 802BE52C 24060002 */  addiu     $a2, $zero, 2
/* 31F2A0 802BE530 0000382D */  daddu     $a3, $zero, $zero
/* 31F2A4 802BE534 AFA00010 */  sw        $zero, 0x10($sp)
/* 31F2A8 802BE538 AFA00014 */  sw        $zero, 0x14($sp)
/* 31F2AC 802BE53C 0C00F589 */  jal       func_8003D624
/* 31F2B0 802BE540 AFA00018 */   sw       $zero, 0x18($sp)
/* 31F2B4 802BE544 3C020007 */  lui       $v0, 7
/* 31F2B8 802BE548 3442000A */  ori       $v0, $v0, 0xa
/* 31F2BC 802BE54C AE220028 */  sw        $v0, 0x28($s1)
/* 31F2C0 802BE550 C640005C */  lwc1      $f0, 0x5c($s2)
/* 31F2C4 802BE554 8E620000 */  lw        $v0, ($s3)
/* 31F2C8 802BE558 AE200014 */  sw        $zero, 0x14($s1)
/* 31F2CC 802BE55C E6200018 */  swc1      $f0, 0x18($s1)
/* 31F2D0 802BE560 A2900000 */  sb        $s0, ($s4)
/* 31F2D4 802BE564 A040007D */  sb        $zero, 0x7d($v0)
/* 31F2D8 802BE568 24020007 */  addiu     $v0, $zero, 7
/* 31F2DC 802BE56C A2820003 */  sb        $v0, 3($s4)
/* 31F2E0 802BE570 3C01802C */  lui       $at, 0x802c
/* 31F2E4 802BE574 AC20FEE4 */  sw        $zero, -0x11c($at)
/* 31F2E8 802BE578 3C01802C */  lui       $at, 0x802c
/* 31F2EC 802BE57C AC20FEE8 */  sw        $zero, -0x118($at)
/* 31F2F0 802BE580 AEA00078 */  sw        $zero, 0x78($s5)
/* 31F2F4 802BE584 080AFD3C */  j         .L802BF4F0
/* 31F2F8 802BE588 AEB00070 */   sw       $s0, 0x70($s5)
/* 31F2FC 802BE58C 86C40012 */  lh        $a0, 0x12($s6)
/* 31F300 802BE590 0480FFCA */  bltz      $a0, .L802BE4BC
/* 31F304 802BE594 27B00020 */   addiu    $s0, $sp, 0x20
/* 31F308 802BE598 0200282D */  daddu     $a1, $s0, $zero
/* 31F30C 802BE59C 27B30024 */  addiu     $s3, $sp, 0x24
/* 31F310 802BE5A0 0260302D */  daddu     $a2, $s3, $zero
/* 31F314 802BE5A4 27B40028 */  addiu     $s4, $sp, 0x28
/* 31F318 802BE5A8 0C016F84 */  jal       get_collider_center
/* 31F31C 802BE5AC 0280382D */   daddu    $a3, $s4, $zero
/* 31F320 802BE5B0 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 31F324 802BE5B4 C7AE0028 */  lwc1      $f14, 0x28($sp)
/* 31F328 802BE5B8 8E460028 */  lw        $a2, 0x28($s2)
/* 31F32C 802BE5BC 0C00A720 */  jal       atan2
/* 31F330 802BE5C0 8E470030 */   lw       $a3, 0x30($s2)
/* 31F334 802BE5C4 0000202D */  daddu     $a0, $zero, $zero
/* 31F338 802BE5C8 0200282D */  daddu     $a1, $s0, $zero
/* 31F33C 802BE5CC 0260302D */  daddu     $a2, $s3, $zero
/* 31F340 802BE5D0 864200B2 */  lh        $v0, 0xb2($s2)
/* 31F344 802BE5D4 0280382D */  daddu     $a3, $s4, $zero
/* 31F348 802BE5D8 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 31F34C 802BE5DC C6400028 */  lwc1      $f0, 0x28($s2)
/* 31F350 802BE5E0 C644002C */  lwc1      $f4, 0x2c($s2)
/* 31F354 802BE5E4 C6460030 */  lwc1      $f6, 0x30($s2)
/* 31F358 802BE5E8 3C013F00 */  lui       $at, 0x3f00
/* 31F35C 802BE5EC 4481A000 */  mtc1      $at, $f20
/* 31F360 802BE5F0 44821000 */  mtc1      $v0, $f2
/* 31F364 802BE5F4 00000000 */  nop       
/* 31F368 802BE5F8 468010A0 */  cvt.s.w   $f2, $f2
/* 31F36C 802BE5FC 864200B2 */  lh        $v0, 0xb2($s2)
/* 31F370 802BE600 46141082 */  mul.s     $f2, $f2, $f20
/* 31F374 802BE604 00000000 */  nop       
/* 31F378 802BE608 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31F37C 802BE60C E7A40024 */  swc1      $f4, 0x24($sp)
/* 31F380 802BE610 E7A60028 */  swc1      $f6, 0x28($sp)
/* 31F384 802BE614 44820000 */  mtc1      $v0, $f0
/* 31F388 802BE618 00000000 */  nop       
/* 31F38C 802BE61C 46800020 */  cvt.s.w   $f0, $f0
/* 31F390 802BE620 46000000 */  add.s     $f0, $f0, $f0
/* 31F394 802BE624 27A2002C */  addiu     $v0, $sp, 0x2c
/* 31F398 802BE628 AFA20018 */  sw        $v0, 0x18($sp)
/* 31F39C 802BE62C E7A00014 */  swc1      $f0, 0x14($sp)
/* 31F3A0 802BE630 0C0AF8A0 */  jal       func_802BE280
/* 31F3A4 802BE634 E7A20010 */   swc1     $f2, 0x10($sp)
/* 31F3A8 802BE638 2403FFFF */  addiu     $v1, $zero, -1
/* 31F3AC 802BE63C 04400004 */  bltz      $v0, .L802BE650
/* 31F3B0 802BE640 AFA20040 */   sw       $v0, 0x40($sp)
/* 31F3B4 802BE644 0C016F6A */  jal       get_collider_type_by_id
/* 31F3B8 802BE648 0040202D */   daddu    $a0, $v0, $zero
/* 31F3BC 802BE64C 304300FF */  andi      $v1, $v0, 0xff
.L802BE650:
/* 31F3C0 802BE650 24020004 */  addiu     $v0, $zero, 4
/* 31F3C4 802BE654 146203A7 */  bne       $v1, $v0, .L802BF4F4
/* 31F3C8 802BE658 24020001 */   addiu    $v0, $zero, 1
/* 31F3CC 802BE65C 3C01802C */  lui       $at, 0x802c
/* 31F3D0 802BE660 AC22FEEC */  sw        $v0, -0x114($at)
/* 31F3D4 802BE664 0C039769 */  jal       set_action_state
/* 31F3D8 802BE668 24040021 */   addiu    $a0, $zero, 0x21
/* 31F3DC 802BE66C 0C038045 */  jal       disable_player_static_collisions
/* 31F3E0 802BE670 00000000 */   nop      
/* 31F3E4 802BE674 0C03805E */  jal       disable_player_input
/* 31F3E8 802BE678 00000000 */   nop      
/* 31F3EC 802BE67C 3C020008 */  lui       $v0, 8
/* 31F3F0 802BE680 AE220080 */  sw        $v0, 0x80($s1)
/* 31F3F4 802BE684 C6400028 */  lwc1      $f0, 0x28($s2)
/* 31F3F8 802BE688 3C064220 */  lui       $a2, 0x4220
/* 31F3FC 802BE68C E6200060 */  swc1      $f0, 0x60($s1)
/* 31F400 802BE690 C640002C */  lwc1      $f0, 0x2c($s2)
/* 31F404 802BE694 E6200064 */  swc1      $f0, 0x64($s1)
/* 31F408 802BE698 C6420030 */  lwc1      $f2, 0x30($s2)
/* 31F40C 802BE69C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 31F410 802BE6A0 26240060 */  addiu     $a0, $s1, 0x60
/* 31F414 802BE6A4 E620000C */  swc1      $f0, 0xc($s1)
/* 31F418 802BE6A8 E6220068 */  swc1      $f2, 0x68($s1)
/* 31F41C 802BE6AC E6400080 */  swc1      $f0, 0x80($s2)
/* 31F420 802BE6B0 8E27000C */  lw        $a3, 0xc($s1)
/* 31F424 802BE6B4 3C0142B4 */  lui       $at, 0x42b4
/* 31F428 802BE6B8 44810000 */  mtc1      $at, $f0
/* 31F42C 802BE6BC 26250068 */  addiu     $a1, $s1, 0x68
/* 31F430 802BE6C0 0C00A7E7 */  jal       add_vec2D_polar
/* 31F434 802BE6C4 E6200034 */   swc1     $f0, 0x34($s1)
/* 31F438 802BE6C8 C6200060 */  lwc1      $f0, 0x60($s1)
/* 31F43C 802BE6CC C6220064 */  lwc1      $f2, 0x64($s1)
/* 31F440 802BE6D0 C6240068 */  lwc1      $f4, 0x68($s1)
/* 31F444 802BE6D4 3C0142C8 */  lui       $at, 0x42c8
/* 31F448 802BE6D8 44813000 */  mtc1      $at, $f6
/* 31F44C 802BE6DC 27A20030 */  addiu     $v0, $sp, 0x30
/* 31F450 802BE6E0 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31F454 802BE6E4 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31F458 802BE6E8 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31F45C 802BE6EC E7A60030 */  swc1      $f6, 0x30($sp)
/* 31F460 802BE6F0 AFA20010 */  sw        $v0, 0x10($sp)
/* 31F464 802BE6F4 C620000C */  lwc1      $f0, 0xc($s1)
/* 31F468 802BE6F8 0200282D */  daddu     $a1, $s0, $zero
/* 31F46C 802BE6FC E7A00014 */  swc1      $f0, 0x14($sp)
/* 31F470 802BE700 862200A6 */  lh        $v0, 0xa6($s1)
/* 31F474 802BE704 0260302D */  daddu     $a2, $s3, $zero
/* 31F478 802BE708 44820000 */  mtc1      $v0, $f0
/* 31F47C 802BE70C 00000000 */  nop       
/* 31F480 802BE710 46800020 */  cvt.s.w   $f0, $f0
/* 31F484 802BE714 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31F488 802BE718 8E240080 */  lw        $a0, 0x80($s1)
/* 31F48C 802BE71C 0C0371DE */  jal       func_800DC778
/* 31F490 802BE720 0280382D */   daddu    $a3, $s4, $zero
/* 31F494 802BE724 3C050007 */  lui       $a1, 7
/* 31F498 802BE728 34A50003 */  ori       $a1, $a1, 3
/* 31F49C 802BE72C 862300A8 */  lh        $v1, 0xa8($s1)
/* 31F4A0 802BE730 3C040001 */  lui       $a0, 1
/* 31F4A4 802BE734 44830000 */  mtc1      $v1, $f0
/* 31F4A8 802BE738 00000000 */  nop       
/* 31F4AC 802BE73C 46800020 */  cvt.s.w   $f0, $f0
/* 31F4B0 802BE740 46140002 */  mul.s     $f0, $f0, $f20
/* 31F4B4 802BE744 00000000 */  nop       
/* 31F4B8 802BE748 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 31F4BC 802BE74C 34840002 */  ori       $a0, $a0, 2
/* 31F4C0 802BE750 AFA20040 */  sw        $v0, 0x40($sp)
/* 31F4C4 802BE754 2402000C */  addiu     $v0, $zero, 0xc
/* 31F4C8 802BE758 46001081 */  sub.s     $f2, $f2, $f0
/* 31F4CC 802BE75C AE250028 */  sw        $a1, 0x28($s1)
/* 31F4D0 802BE760 A622008E */  sh        $v0, 0x8e($s1)
/* 31F4D4 802BE764 0C037FBF */  jal       func_800DFEFC
/* 31F4D8 802BE768 E6220064 */   swc1     $f2, 0x64($s1)
/* 31F4DC 802BE76C 8EA20070 */  lw        $v0, 0x70($s5)
/* 31F4E0 802BE770 24420001 */  addiu     $v0, $v0, 1
/* 31F4E4 802BE774 080AFD3C */  j         .L802BF4F0
/* 31F4E8 802BE778 AEA20070 */   sw       $v0, 0x70($s5)
/* 31F4EC 802BE77C C6200060 */  lwc1      $f0, 0x60($s1)
/* 31F4F0 802BE780 C62A0038 */  lwc1      $f10, 0x38($s1)
/* 31F4F4 802BE784 8622008E */  lh        $v0, 0x8e($s1)
/* 31F4F8 802BE788 C6240064 */  lwc1      $f4, 0x64($s1)
/* 31F4FC 802BE78C C628003C */  lwc1      $f8, 0x3c($s1)
/* 31F500 802BE790 C6260040 */  lwc1      $f6, 0x40($s1)
/* 31F504 802BE794 44821000 */  mtc1      $v0, $f2
/* 31F508 802BE798 00000000 */  nop       
/* 31F50C 802BE79C 468010A0 */  cvt.s.w   $f2, $f2
/* 31F510 802BE7A0 0040202D */  daddu     $a0, $v0, $zero
/* 31F514 802BE7A4 460A0001 */  sub.s     $f0, $f0, $f10
/* 31F518 802BE7A8 0080182D */  daddu     $v1, $a0, $zero
/* 31F51C 802BE7AC 9622008E */  lhu       $v0, 0x8e($s1)
/* 31F520 802BE7B0 46082101 */  sub.s     $f4, $f4, $f8
/* 31F524 802BE7B4 2442FFFF */  addiu     $v0, $v0, -1
/* 31F528 802BE7B8 A622008E */  sh        $v0, 0x8e($s1)
/* 31F52C 802BE7BC 00021400 */  sll       $v0, $v0, 0x10
/* 31F530 802BE7C0 46020003 */  div.s     $f0, $f0, $f2
/* 31F534 802BE7C4 46005280 */  add.s     $f10, $f10, $f0
/* 31F538 802BE7C8 C6220068 */  lwc1      $f2, 0x68($s1)
/* 31F53C 802BE7CC 44840000 */  mtc1      $a0, $f0
/* 31F540 802BE7D0 00000000 */  nop       
/* 31F544 802BE7D4 46800020 */  cvt.s.w   $f0, $f0
/* 31F548 802BE7D8 46061081 */  sub.s     $f2, $f2, $f6
/* 31F54C 802BE7DC 46002103 */  div.s     $f4, $f4, $f0
/* 31F550 802BE7E0 44830000 */  mtc1      $v1, $f0
/* 31F554 802BE7E4 00000000 */  nop       
/* 31F558 802BE7E8 46800020 */  cvt.s.w   $f0, $f0
/* 31F55C 802BE7EC 46044200 */  add.s     $f8, $f8, $f4
/* 31F560 802BE7F0 00021C03 */  sra       $v1, $v0, 0x10
/* 31F564 802BE7F4 46001083 */  div.s     $f2, $f2, $f0
/* 31F568 802BE7F8 46023180 */  add.s     $f6, $f6, $f2
/* 31F56C 802BE7FC E62A0038 */  swc1      $f10, 0x38($s1)
/* 31F570 802BE800 E628003C */  swc1      $f8, 0x3c($s1)
/* 31F574 802BE804 1060000D */  beqz      $v1, .L802BE83C
/* 31F578 802BE808 E6260040 */   swc1     $f6, 0x40($s1)
/* 31F57C 802BE80C 24020002 */  addiu     $v0, $zero, 2
/* 31F580 802BE810 14620338 */  bne       $v1, $v0, .L802BF4F4
/* 31F584 802BE814 0000102D */   daddu    $v0, $zero, $zero
/* 31F588 802BE818 24042081 */  addiu     $a0, $zero, 0x2081
/* 31F58C 802BE81C 0000282D */  daddu     $a1, $zero, $zero
/* 31F590 802BE820 0C052742 */  jal       play_sound_at_npc
/* 31F594 802BE824 2406FFFC */   addiu    $a2, $zero, -4
/* 31F598 802BE828 3C040001 */  lui       $a0, 1
/* 31F59C 802BE82C 0C037FBF */  jal       func_800DFEFC
/* 31F5A0 802BE830 34840006 */   ori      $a0, $a0, 6
/* 31F5A4 802BE834 080AFD3D */  j         .L802BF4F4
/* 31F5A8 802BE838 0000102D */   daddu    $v0, $zero, $zero
.L802BE83C:
/* 31F5AC 802BE83C 0220202D */  daddu     $a0, $s1, $zero
/* 31F5B0 802BE840 8E220000 */  lw        $v0, ($s1)
/* 31F5B4 802BE844 3C030001 */  lui       $v1, 1
/* 31F5B8 802BE848 AE230080 */  sw        $v1, 0x80($s1)
/* 31F5BC 802BE84C 2403FDBF */  addiu     $v1, $zero, -0x241
/* 31F5C0 802BE850 34420008 */  ori       $v0, $v0, 8
/* 31F5C4 802BE854 00431024 */  and       $v0, $v0, $v1
/* 31F5C8 802BE858 0C00EAFF */  jal       disable_npc_shadow
/* 31F5CC 802BE85C AE220000 */   sw       $v0, ($s1)
/* 31F5D0 802BE860 0220202D */  daddu     $a0, $s1, $zero
/* 31F5D4 802BE864 24050004 */  addiu     $a1, $zero, 4
/* 31F5D8 802BE868 24060002 */  addiu     $a2, $zero, 2
/* 31F5DC 802BE86C 0000382D */  daddu     $a3, $zero, $zero
/* 31F5E0 802BE870 AFA00010 */  sw        $zero, 0x10($sp)
/* 31F5E4 802BE874 AFA00014 */  sw        $zero, 0x14($sp)
/* 31F5E8 802BE878 0C00F589 */  jal       func_8003D624
/* 31F5EC 802BE87C AFA00018 */   sw       $zero, 0x18($sp)
/* 31F5F0 802BE880 3C020007 */  lui       $v0, 7
/* 31F5F4 802BE884 3442000A */  ori       $v0, $v0, 0xa
/* 31F5F8 802BE888 3C030040 */  lui       $v1, 0x40
/* 31F5FC 802BE88C AE220028 */  sw        $v0, 0x28($s1)
/* 31F600 802BE890 C64C0028 */  lwc1      $f12, 0x28($s2)
/* 31F604 802BE894 8E420000 */  lw        $v0, ($s2)
/* 31F608 802BE898 C64E0030 */  lwc1      $f14, 0x30($s2)
/* 31F60C 802BE89C 00431025 */  or        $v0, $v0, $v1
/* 31F610 802BE8A0 AE420000 */  sw        $v0, ($s2)
/* 31F614 802BE8A4 8E260060 */  lw        $a2, 0x60($s1)
/* 31F618 802BE8A8 0C00A7B5 */  jal       dist2D
/* 31F61C 802BE8AC 8E270068 */   lw       $a3, 0x68($s1)
/* 31F620 802BE8B0 3C0140A0 */  lui       $at, 0x40a0
/* 31F624 802BE8B4 44811000 */  mtc1      $at, $f2
/* 31F628 802BE8B8 3C013F19 */  lui       $at, 0x3f19
/* 31F62C 802BE8BC 3421999A */  ori       $at, $at, 0x999a
/* 31F630 802BE8C0 44812000 */  mtc1      $at, $f4
/* 31F634 802BE8C4 C6260064 */  lwc1      $f6, 0x64($s1)
/* 31F638 802BE8C8 E622001C */  swc1      $f2, 0x1c($s1)
/* 31F63C 802BE8CC E6240014 */  swc1      $f4, 0x14($s1)
/* 31F640 802BE8D0 C642002C */  lwc1      $f2, 0x2c($s2)
/* 31F644 802BE8D4 3C040001 */  lui       $a0, 1
/* 31F648 802BE8D8 46023181 */  sub.s     $f6, $f6, $f2
/* 31F64C 802BE8DC C622001C */  lwc1      $f2, 0x1c($s1)
/* 31F650 802BE8E0 34840007 */  ori       $a0, $a0, 7
/* 31F654 802BE8E4 46021080 */  add.s     $f2, $f2, $f2
/* 31F658 802BE8E8 E7A00030 */  swc1      $f0, 0x30($sp)
/* 31F65C 802BE8EC E7A60024 */  swc1      $f6, 0x24($sp)
/* 31F660 802BE8F0 46041083 */  div.s     $f2, $f2, $f4
/* 31F664 802BE8F4 4600140D */  trunc.w.s $f16, $f2
/* 31F668 802BE8F8 44028000 */  mfc1      $v0, $f16
/* 31F66C 802BE8FC 00000000 */  nop       
/* 31F670 802BE900 A622008E */  sh        $v0, 0x8e($s1)
/* 31F674 802BE904 00021400 */  sll       $v0, $v0, 0x10
/* 31F678 802BE908 00021403 */  sra       $v0, $v0, 0x10
/* 31F67C 802BE90C 44824000 */  mtc1      $v0, $f8
/* 31F680 802BE910 00000000 */  nop       
/* 31F684 802BE914 46804220 */  cvt.s.w   $f8, $f8
/* 31F688 802BE918 8623008E */  lh        $v1, 0x8e($s1)
/* 31F68C 802BE91C C622001C */  lwc1      $f2, 0x1c($s1)
/* 31F690 802BE920 44832000 */  mtc1      $v1, $f4
/* 31F694 802BE924 00000000 */  nop       
/* 31F698 802BE928 46802120 */  cvt.s.w   $f4, $f4
/* 31F69C 802BE92C 46043183 */  div.s     $f6, $f6, $f4
/* 31F6A0 802BE930 46061080 */  add.s     $f2, $f2, $f6
/* 31F6A4 802BE934 46080003 */  div.s     $f0, $f0, $f8
/* 31F6A8 802BE938 E6200018 */  swc1      $f0, 0x18($s1)
/* 31F6AC 802BE93C 0C037FBF */  jal       func_800DFEFC
/* 31F6B0 802BE940 E622001C */   swc1     $f2, 0x1c($s1)
/* 31F6B4 802BE944 8EA20070 */  lw        $v0, 0x70($s5)
/* 31F6B8 802BE948 24420001 */  addiu     $v0, $v0, 1
/* 31F6BC 802BE94C AEA20070 */  sw        $v0, 0x70($s5)
/* 31F6C0 802BE950 862200A8 */  lh        $v0, 0xa8($s1)
/* 31F6C4 802BE954 3C013F00 */  lui       $at, 0x3f00
/* 31F6C8 802BE958 44811000 */  mtc1      $at, $f2
/* 31F6CC 802BE95C 44820000 */  mtc1      $v0, $f0
/* 31F6D0 802BE960 00000000 */  nop       
/* 31F6D4 802BE964 46800020 */  cvt.s.w   $f0, $f0
/* 31F6D8 802BE968 46020002 */  mul.s     $f0, $f0, $f2
/* 31F6DC 802BE96C 00000000 */  nop       
/* 31F6E0 802BE970 C6220064 */  lwc1      $f2, 0x64($s1)
/* 31F6E4 802BE974 AFA00010 */  sw        $zero, 0x10($sp)
/* 31F6E8 802BE978 46001080 */  add.s     $f2, $f2, $f0
/* 31F6EC 802BE97C 8E250038 */  lw        $a1, 0x38($s1)
/* 31F6F0 802BE980 8E270040 */  lw        $a3, 0x40($s1)
/* 31F6F4 802BE984 44061000 */  mfc1      $a2, $f2
/* 31F6F8 802BE988 0C01C16C */  jal       func_800705B0
/* 31F6FC 802BE98C 0000202D */   daddu    $a0, $zero, $zero
/* 31F700 802BE990 080AFD3D */  j         .L802BF4F4
/* 31F704 802BE994 0000102D */   daddu    $v0, $zero, $zero
/* 31F708 802BE998 862200A8 */  lh        $v0, 0xa8($s1)
/* 31F70C 802BE99C 3C013F00 */  lui       $at, 0x3f00
/* 31F710 802BE9A0 44811000 */  mtc1      $at, $f2
/* 31F714 802BE9A4 44820000 */  mtc1      $v0, $f0
/* 31F718 802BE9A8 00000000 */  nop       
/* 31F71C 802BE9AC 46800020 */  cvt.s.w   $f0, $f0
/* 31F720 802BE9B0 46020002 */  mul.s     $f0, $f0, $f2
/* 31F724 802BE9B4 00000000 */  nop       
/* 31F728 802BE9B8 C6220064 */  lwc1      $f2, 0x64($s1)
/* 31F72C 802BE9BC AFA00010 */  sw        $zero, 0x10($sp)
/* 31F730 802BE9C0 46001080 */  add.s     $f2, $f2, $f0
/* 31F734 802BE9C4 8E250038 */  lw        $a1, 0x38($s1)
/* 31F738 802BE9C8 8E270040 */  lw        $a3, 0x40($s1)
/* 31F73C 802BE9CC 44061000 */  mfc1      $a2, $f2
/* 31F740 802BE9D0 0C01C16C */  jal       func_800705B0
/* 31F744 802BE9D4 0000202D */   daddu    $a0, $zero, $zero
/* 31F748 802BE9D8 8EA20070 */  lw        $v0, 0x70($s5)
/* 31F74C 802BE9DC 24420001 */  addiu     $v0, $v0, 1
/* 31F750 802BE9E0 AEA20070 */  sw        $v0, 0x70($s5)
/* 31F754 802BE9E4 C640002C */  lwc1      $f0, 0x2c($s2)
/* 31F758 802BE9E8 C622001C */  lwc1      $f2, 0x1c($s1)
/* 31F75C 802BE9EC 46020000 */  add.s     $f0, $f0, $f2
/* 31F760 802BE9F0 26440028 */  addiu     $a0, $s2, 0x28
/* 31F764 802BE9F4 E640002C */  swc1      $f0, 0x2c($s2)
/* 31F768 802BE9F8 C620001C */  lwc1      $f0, 0x1c($s1)
/* 31F76C 802BE9FC C6220014 */  lwc1      $f2, 0x14($s1)
/* 31F770 802BEA00 8E260018 */  lw        $a2, 0x18($s1)
/* 31F774 802BEA04 46020001 */  sub.s     $f0, $f0, $f2
/* 31F778 802BEA08 8E27000C */  lw        $a3, 0xc($s1)
/* 31F77C 802BEA0C 26450030 */  addiu     $a1, $s2, 0x30
/* 31F780 802BEA10 0C00A7E7 */  jal       add_vec2D_polar
/* 31F784 802BEA14 E620001C */   swc1     $f0, 0x1c($s1)
/* 31F788 802BEA18 C622001C */  lwc1      $f2, 0x1c($s1)
/* 31F78C 802BEA1C 44800000 */  mtc1      $zero, $f0
/* 31F790 802BEA20 00000000 */  nop       
/* 31F794 802BEA24 4600103E */  c.le.s    $f2, $f0
/* 31F798 802BEA28 00000000 */  nop       
/* 31F79C 802BEA2C 45000004 */  bc1f      .L802BEA40
/* 31F7A0 802BEA30 00000000 */   nop      
/* 31F7A4 802BEA34 3C040001 */  lui       $a0, 1
/* 31F7A8 802BEA38 0C037FBF */  jal       func_800DFEFC
/* 31F7AC 802BEA3C 34840008 */   ori      $a0, $a0, 8
.L802BEA40:
/* 31F7B0 802BEA40 C6400028 */  lwc1      $f0, 0x28($s2)
/* 31F7B4 802BEA44 C642002C */  lwc1      $f2, 0x2c($s2)
/* 31F7B8 802BEA48 C6440030 */  lwc1      $f4, 0x30($s2)
/* 31F7BC 802BEA4C 3C02800B */  lui       $v0, %hi(gCameras)
/* 31F7C0 802BEA50 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 31F7C4 802BEA54 E4400060 */  swc1      $f0, 0x60($v0)
/* 31F7C8 802BEA58 E4420064 */  swc1      $f2, 0x64($v0)
/* 31F7CC 802BEA5C E4440068 */  swc1      $f4, 0x68($v0)
/* 31F7D0 802BEA60 8622008E */  lh        $v0, 0x8e($s1)
/* 31F7D4 802BEA64 9623008E */  lhu       $v1, 0x8e($s1)
/* 31F7D8 802BEA68 144002A0 */  bnez      $v0, .L802BF4EC
/* 31F7DC 802BEA6C 2462FFFF */   addiu    $v0, $v1, -1
/* 31F7E0 802BEA70 0C039769 */  jal       set_action_state
/* 31F7E4 802BEA74 24040021 */   addiu    $a0, $zero, 0x21
/* 31F7E8 802BEA78 0C038039 */  jal       disable_player_shadow
/* 31F7EC 802BEA7C 00000000 */   nop      
/* 31F7F0 802BEA80 3C03FFBF */  lui       $v1, 0xffbf
/* 31F7F4 802BEA84 3463FFFF */  ori       $v1, $v1, 0xffff
/* 31F7F8 802BEA88 3C040008 */  lui       $a0, 8
/* 31F7FC 802BEA8C 8E420000 */  lw        $v0, ($s2)
/* 31F800 802BEA90 3484000F */  ori       $a0, $a0, 0xf
/* 31F804 802BEA94 00431024 */  and       $v0, $v0, $v1
/* 31F808 802BEA98 0C037FDE */  jal       func_800DFF78
/* 31F80C 802BEA9C AE420000 */   sw       $v0, ($s2)
/* 31F810 802BEAA0 24042013 */  addiu     $a0, $zero, 0x2013
/* 31F814 802BEAA4 0000282D */  daddu     $a1, $zero, $zero
/* 31F818 802BEAA8 0C052742 */  jal       play_sound_at_npc
/* 31F81C 802BEAAC 2406FFFC */   addiu    $a2, $zero, -4
/* 31F820 802BEAB0 C6200038 */  lwc1      $f0, 0x38($s1)
/* 31F824 802BEAB4 3C014040 */  lui       $at, 0x4040
/* 31F828 802BEAB8 44811000 */  mtc1      $at, $f2
/* 31F82C 802BEABC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 31F830 802BEAC0 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 31F834 802BEAC4 E6400028 */  swc1      $f0, 0x28($s2)
/* 31F838 802BEAC8 C620003C */  lwc1      $f0, 0x3c($s1)
/* 31F83C 802BEACC E640002C */  swc1      $f0, 0x2c($s2)
/* 31F840 802BEAD0 C6200040 */  lwc1      $f0, 0x40($s1)
/* 31F844 802BEAD4 E6400030 */  swc1      $f0, 0x30($s2)
/* 31F848 802BEAD8 C620000C */  lwc1      $f0, 0xc($s1)
/* 31F84C 802BEADC 24020001 */  addiu     $v0, $zero, 1
/* 31F850 802BEAE0 E6400080 */  swc1      $f0, 0x80($s2)
/* 31F854 802BEAE4 E6220018 */  swc1      $f2, 0x18($s1)
/* 31F858 802BEAE8 A2820000 */  sb        $v0, ($s4)
/* 31F85C 802BEAEC 24020007 */  addiu     $v0, $zero, 7
/* 31F860 802BEAF0 A060007D */  sb        $zero, 0x7d($v1)
/* 31F864 802BEAF4 A2820003 */  sb        $v0, 3($s4)
/* 31F868 802BEAF8 24020001 */  addiu     $v0, $zero, 1
/* 31F86C 802BEAFC 3C01802C */  lui       $at, 0x802c
/* 31F870 802BEB00 AC20FEE4 */  sw        $zero, -0x11c($at)
/* 31F874 802BEB04 3C01802C */  lui       $at, 0x802c
/* 31F878 802BEB08 AC20FEE8 */  sw        $zero, -0x118($at)
/* 31F87C 802BEB0C AEA00078 */  sw        $zero, 0x78($s5)
/* 31F880 802BEB10 080AFD3C */  j         .L802BF4F0
/* 31F884 802BEB14 AEA20070 */   sw       $v0, 0x70($s5)
/* 31F888 802BEB18 0220202D */  daddu     $a0, $s1, $zero
/* 31F88C 802BEB1C 8E420004 */  lw        $v0, 4($s2)
/* 31F890 802BEB20 3C030040 */  lui       $v1, 0x40
/* 31F894 802BEB24 00431025 */  or        $v0, $v0, $v1
/* 31F898 802BEB28 0C0AF505 */  jal       func_802BD414
/* 31F89C 802BEB2C AE420004 */   sw       $v0, 4($s2)
/* 31F8A0 802BEB30 3C10802C */  lui       $s0, 0x802c
/* 31F8A4 802BEB34 2610FEE4 */  addiu     $s0, $s0, -0x11c
/* 31F8A8 802BEB38 8E020000 */  lw        $v0, ($s0)
/* 31F8AC 802BEB3C 14400052 */  bnez      $v0, .L802BEC88
/* 31F8B0 802BEB40 00000000 */   nop      
/* 31F8B4 802BEB44 8EA30078 */  lw        $v1, 0x78($s5)
/* 31F8B8 802BEB48 24620001 */  addiu     $v0, $v1, 1
/* 31F8BC 802BEB4C AEA20078 */  sw        $v0, 0x78($s5)
/* 31F8C0 802BEB50 28420015 */  slti      $v0, $v0, 0x15
/* 31F8C4 802BEB54 14400002 */  bnez      $v0, .L802BEB60
/* 31F8C8 802BEB58 2462FFD9 */   addiu    $v0, $v1, -0x27
/* 31F8CC 802BEB5C AEA20078 */  sw        $v0, 0x78($s5)
.L802BEB60:
/* 31F8D0 802BEB60 8EA20078 */  lw        $v0, 0x78($s5)
/* 31F8D4 802BEB64 3C013E00 */  lui       $at, 0x3e00
/* 31F8D8 802BEB68 44810000 */  mtc1      $at, $f0
/* 31F8DC 802BEB6C 04420001 */  bltzl     $v0, .L802BEB74
/* 31F8E0 802BEB70 00021023 */   negu     $v0, $v0
.L802BEB74:
/* 31F8E4 802BEB74 44821000 */  mtc1      $v0, $f2
/* 31F8E8 802BEB78 00000000 */  nop       
/* 31F8EC 802BEB7C 468010A0 */  cvt.s.w   $f2, $f2
/* 31F8F0 802BEB80 46001082 */  mul.s     $f2, $f2, $f0
/* 31F8F4 802BEB84 00000000 */  nop       
/* 31F8F8 802BEB88 C6200064 */  lwc1      $f0, 0x64($s1)
/* 31F8FC 802BEB8C 46020000 */  add.s     $f0, $f0, $f2
/* 31F900 802BEB90 E620003C */  swc1      $f0, 0x3c($s1)
/* 31F904 802BEB94 8EA30078 */  lw        $v1, 0x78($s5)
/* 31F908 802BEB98 24020005 */  addiu     $v0, $zero, 5
/* 31F90C 802BEB9C 14620011 */  bne       $v1, $v0, .L802BEBE4
/* 31F910 802BEBA0 27A4002C */   addiu    $a0, $sp, 0x2c
/* 31F914 802BEBA4 0C0AF483 */  jal       func_802BD20C
/* 31F918 802BEBA8 27A50034 */   addiu    $a1, $sp, 0x34
/* 31F91C 802BEBAC 8E020000 */  lw        $v0, ($s0)
/* 31F920 802BEBB0 1440000C */  bnez      $v0, .L802BEBE4
/* 31F924 802BEBB4 00000000 */   nop      
/* 31F928 802BEBB8 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 31F92C 802BEBBC 44800000 */  mtc1      $zero, $f0
/* 31F930 802BEBC0 00000000 */  nop       
/* 31F934 802BEBC4 46001032 */  c.eq.s    $f2, $f0
/* 31F938 802BEBC8 00000000 */  nop       
/* 31F93C 802BEBCC 45010002 */  bc1t      .L802BEBD8
/* 31F940 802BEBD0 24042014 */   addiu    $a0, $zero, 0x2014
/* 31F944 802BEBD4 24042015 */  addiu     $a0, $zero, 0x2015
.L802BEBD8:
/* 31F948 802BEBD8 0000282D */  daddu     $a1, $zero, $zero
/* 31F94C 802BEBDC 0C052742 */  jal       play_sound_at_npc
/* 31F950 802BEBE0 2406FFFC */   addiu    $a2, $zero, -4
.L802BEBE4:
/* 31F954 802BEBE4 3C01802C */  lui       $at, 0x802c
/* 31F958 802BEBE8 C420FEF8 */  lwc1      $f0, -0x108($at)
/* 31F95C 802BEBEC 44802000 */  mtc1      $zero, $f4
/* 31F960 802BEBF0 00000000 */  nop       
/* 31F964 802BEBF4 46040032 */  c.eq.s    $f0, $f4
/* 31F968 802BEBF8 00000000 */  nop       
/* 31F96C 802BEBFC 45000024 */  bc1f      .L802BEC90
/* 31F970 802BEC00 00000000 */   nop      
/* 31F974 802BEC04 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 31F978 802BEC08 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 31F97C 802BEC0C 94430134 */  lhu       $v1, 0x134($v0)
/* 31F980 802BEC10 3C02CCCC */  lui       $v0, 0xcccc
/* 31F984 802BEC14 3442CCCD */  ori       $v0, $v0, 0xcccd
/* 31F988 802BEC18 00620019 */  multu     $v1, $v0
/* 31F98C 802BEC1C 00004810 */  mfhi      $t1
/* 31F990 802BEC20 000920C2 */  srl       $a0, $t1, 3
/* 31F994 802BEC24 00041080 */  sll       $v0, $a0, 2
/* 31F998 802BEC28 00441021 */  addu      $v0, $v0, $a0
/* 31F99C 802BEC2C 00021040 */  sll       $v0, $v0, 1
/* 31F9A0 802BEC30 00621823 */  subu      $v1, $v1, $v0
/* 31F9A4 802BEC34 3063FFFF */  andi      $v1, $v1, 0xffff
/* 31F9A8 802BEC38 14600015 */  bnez      $v1, .L802BEC90
/* 31F9AC 802BEC3C 00000000 */   nop      
/* 31F9B0 802BEC40 862200A8 */  lh        $v0, 0xa8($s1)
/* 31F9B4 802BEC44 3C013F00 */  lui       $at, 0x3f00
/* 31F9B8 802BEC48 44811000 */  mtc1      $at, $f2
/* 31F9BC 802BEC4C 44820000 */  mtc1      $v0, $f0
/* 31F9C0 802BEC50 00000000 */  nop       
/* 31F9C4 802BEC54 46800020 */  cvt.s.w   $f0, $f0
/* 31F9C8 802BEC58 46020002 */  mul.s     $f0, $f0, $f2
/* 31F9CC 802BEC5C 00000000 */  nop       
/* 31F9D0 802BEC60 C6220064 */  lwc1      $f2, 0x64($s1)
/* 31F9D4 802BEC64 E7A40010 */  swc1      $f4, 0x10($sp)
/* 31F9D8 802BEC68 46001080 */  add.s     $f2, $f2, $f0
/* 31F9DC 802BEC6C 8E250038 */  lw        $a1, 0x38($s1)
/* 31F9E0 802BEC70 8E270040 */  lw        $a3, 0x40($s1)
/* 31F9E4 802BEC74 44061000 */  mfc1      $a2, $f2
/* 31F9E8 802BEC78 0C01C16C */  jal       func_800705B0
/* 31F9EC 802BEC7C 0000202D */   daddu    $a0, $zero, $zero
/* 31F9F0 802BEC80 080AFB24 */  j         .L802BEC90
/* 31F9F4 802BEC84 00000000 */   nop      
.L802BEC88:
/* 31F9F8 802BEC88 C6200064 */  lwc1      $f0, 0x64($s1)
/* 31F9FC 802BEC8C E620003C */  swc1      $f0, 0x3c($s1)
.L802BEC90:
/* 31FA00 802BEC90 8E420004 */  lw        $v0, 4($s2)
/* 31FA04 802BEC94 3C030040 */  lui       $v1, 0x40
/* 31FA08 802BEC98 00431024 */  and       $v0, $v0, $v1
/* 31FA0C 802BEC9C 14400003 */  bnez      $v0, .L802BECAC
/* 31FA10 802BECA0 00000000 */   nop      
/* 31FA14 802BECA4 0C0AF440 */  jal       func_802BD100
/* 31FA18 802BECA8 00000000 */   nop      
.L802BECAC:
/* 31FA1C 802BECAC 3C06802C */  lui       $a2, 0x802c
/* 31FA20 802BECB0 8CC6FEE4 */  lw        $a2, -0x11c($a2)
/* 31FA24 802BECB4 24020001 */  addiu     $v0, $zero, 1
/* 31FA28 802BECB8 14C20028 */  bne       $a2, $v0, .L802BED5C
/* 31FA2C 802BECBC 00000000 */   nop      
/* 31FA30 802BECC0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 31FA34 802BECC4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 31FA38 802BECC8 94440134 */  lhu       $a0, 0x134($v0)
/* 31FA3C 802BECCC 3C03AF28 */  lui       $v1, 0xaf28
/* 31FA40 802BECD0 34636BCB */  ori       $v1, $v1, 0x6bcb
/* 31FA44 802BECD4 00830019 */  multu     $a0, $v1
/* 31FA48 802BECD8 00001810 */  mfhi      $v1
/* 31FA4C 802BECDC 00831023 */  subu      $v0, $a0, $v1
/* 31FA50 802BECE0 00021042 */  srl       $v0, $v0, 1
/* 31FA54 802BECE4 00621821 */  addu      $v1, $v1, $v0
/* 31FA58 802BECE8 00031902 */  srl       $v1, $v1, 4
/* 31FA5C 802BECEC 00031080 */  sll       $v0, $v1, 2
/* 31FA60 802BECF0 00431021 */  addu      $v0, $v0, $v1
/* 31FA64 802BECF4 00021080 */  sll       $v0, $v0, 2
/* 31FA68 802BECF8 00431023 */  subu      $v0, $v0, $v1
/* 31FA6C 802BECFC 00822023 */  subu      $a0, $a0, $v0
/* 31FA70 802BED00 3084FFFF */  andi      $a0, $a0, 0xffff
/* 31FA74 802BED04 14800047 */  bnez      $a0, .L802BEE24
/* 31FA78 802BED08 00000000 */   nop      
/* 31FA7C 802BED0C 862200A8 */  lh        $v0, 0xa8($s1)
/* 31FA80 802BED10 3C013F00 */  lui       $at, 0x3f00
/* 31FA84 802BED14 44810000 */  mtc1      $at, $f0
/* 31FA88 802BED18 44822000 */  mtc1      $v0, $f4
/* 31FA8C 802BED1C 00000000 */  nop       
/* 31FA90 802BED20 46802120 */  cvt.s.w   $f4, $f4
/* 31FA94 802BED24 46002102 */  mul.s     $f4, $f4, $f0
/* 31FA98 802BED28 00000000 */  nop       
/* 31FA9C 802BED2C C622003C */  lwc1      $f2, 0x3c($s1)
/* 31FAA0 802BED30 3C01802C */  lui       $at, 0x802c
/* 31FAA4 802BED34 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31FAA8 802BED38 46020001 */  sub.s     $f0, $f0, $f2
/* 31FAAC 802BED3C C6220064 */  lwc1      $f2, 0x64($s1)
/* 31FAB0 802BED40 E7A00010 */  swc1      $f0, 0x10($sp)
/* 31FAB4 802BED44 46041080 */  add.s     $f2, $f2, $f4
/* 31FAB8 802BED48 8E250038 */  lw        $a1, 0x38($s1)
/* 31FABC 802BED4C 8E270040 */  lw        $a3, 0x40($s1)
/* 31FAC0 802BED50 44061000 */  mfc1      $a2, $f2
/* 31FAC4 802BED54 080AFB87 */  j         .L802BEE1C
/* 31FAC8 802BED58 00000000 */   nop      
.L802BED5C:
/* 31FACC 802BED5C 3C01802C */  lui       $at, 0x802c
/* 31FAD0 802BED60 C420FEF8 */  lwc1      $f0, -0x108($at)
/* 31FAD4 802BED64 44803000 */  mtc1      $zero, $f6
/* 31FAD8 802BED68 00000000 */  nop       
/* 31FADC 802BED6C 46060032 */  c.eq.s    $f0, $f6
/* 31FAE0 802BED70 00000000 */  nop       
/* 31FAE4 802BED74 4501002B */  bc1t      .L802BEE24
/* 31FAE8 802BED78 28C20002 */   slti     $v0, $a2, 2
/* 31FAEC 802BED7C 10400029 */  beqz      $v0, .L802BEE24
/* 31FAF0 802BED80 3C032492 */   lui      $v1, 0x2492
/* 31FAF4 802BED84 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 31FAF8 802BED88 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 31FAFC 802BED8C 94440134 */  lhu       $a0, 0x134($v0)
/* 31FB00 802BED90 34634925 */  ori       $v1, $v1, 0x4925
/* 31FB04 802BED94 00830019 */  multu     $a0, $v1
/* 31FB08 802BED98 00001810 */  mfhi      $v1
/* 31FB0C 802BED9C 00831023 */  subu      $v0, $a0, $v1
/* 31FB10 802BEDA0 00021042 */  srl       $v0, $v0, 1
/* 31FB14 802BEDA4 00621821 */  addu      $v1, $v1, $v0
/* 31FB18 802BEDA8 00031882 */  srl       $v1, $v1, 2
/* 31FB1C 802BEDAC 000310C0 */  sll       $v0, $v1, 3
/* 31FB20 802BEDB0 00431023 */  subu      $v0, $v0, $v1
/* 31FB24 802BEDB4 00822023 */  subu      $a0, $a0, $v0
/* 31FB28 802BEDB8 3084FFFF */  andi      $a0, $a0, 0xffff
/* 31FB2C 802BEDBC 14800019 */  bnez      $a0, .L802BEE24
/* 31FB30 802BEDC0 26250038 */   addiu    $a1, $s1, 0x38
/* 31FB34 802BEDC4 862200A8 */  lh        $v0, 0xa8($s1)
/* 31FB38 802BEDC8 3C013F00 */  lui       $at, 0x3f00
/* 31FB3C 802BEDCC 44811000 */  mtc1      $at, $f2
/* 31FB40 802BEDD0 44820000 */  mtc1      $v0, $f0
/* 31FB44 802BEDD4 00000000 */  nop       
/* 31FB48 802BEDD8 46800020 */  cvt.s.w   $f0, $f0
/* 31FB4C 802BEDDC 46020002 */  mul.s     $f0, $f0, $f2
/* 31FB50 802BEDE0 00000000 */  nop       
/* 31FB54 802BEDE4 C6220064 */  lwc1      $f2, 0x64($s1)
/* 31FB58 802BEDE8 26270040 */  addiu     $a3, $s1, 0x40
/* 31FB5C 802BEDEC 10C00007 */  beqz      $a2, .L802BEE0C
/* 31FB60 802BEDF0 46001100 */   add.s    $f4, $f2, $f0
/* 31FB64 802BEDF4 3C01802C */  lui       $at, 0x802c
/* 31FB68 802BEDF8 C420FEE0 */  lwc1      $f0, -0x120($at)
/* 31FB6C 802BEDFC C622003C */  lwc1      $f2, 0x3c($s1)
/* 31FB70 802BEE00 46020001 */  sub.s     $f0, $f0, $f2
/* 31FB74 802BEE04 080AFB84 */  j         .L802BEE10
/* 31FB78 802BEE08 E7A00010 */   swc1     $f0, 0x10($sp)
.L802BEE0C:
/* 31FB7C 802BEE0C E7A60010 */  swc1      $f6, 0x10($sp)
.L802BEE10:
/* 31FB80 802BEE10 8CA50000 */  lw        $a1, ($a1)
/* 31FB84 802BEE14 44062000 */  mfc1      $a2, $f4
/* 31FB88 802BEE18 8CE70000 */  lw        $a3, ($a3)
.L802BEE1C:
/* 31FB8C 802BEE1C 0C01C16C */  jal       func_800705B0
/* 31FB90 802BEE20 0000202D */   daddu    $a0, $zero, $zero
.L802BEE24:
/* 31FB94 802BEE24 C6200038 */  lwc1      $f0, 0x38($s1)
/* 31FB98 802BEE28 3C01802C */  lui       $at, 0x802c
/* 31FB9C 802BEE2C C422FEE0 */  lwc1      $f2, -0x120($at)
/* 31FBA0 802BEE30 3C03800B */  lui       $v1, %hi(gCameras)
/* 31FBA4 802BEE34 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 31FBA8 802BEE38 E4600060 */  swc1      $f0, 0x60($v1)
/* 31FBAC 802BEE3C E4620064 */  swc1      $f2, 0x64($v1)
/* 31FBB0 802BEE40 8E82000C */  lw        $v0, 0xc($s4)
/* 31FBB4 802BEE44 C6200040 */  lwc1      $f0, 0x40($s1)
/* 31FBB8 802BEE48 30424004 */  andi      $v0, $v0, 0x4004
/* 31FBBC 802BEE4C 14400006 */  bnez      $v0, .L802BEE68
/* 31FBC0 802BEE50 E4600068 */   swc1     $f0, 0x68($v1)
/* 31FBC4 802BEE54 3C02802C */  lui       $v0, 0x802c
/* 31FBC8 802BEE58 8C42FEF0 */  lw        $v0, -0x110($v0)
/* 31FBCC 802BEE5C 2842001E */  slti      $v0, $v0, 0x1e
/* 31FBD0 802BEE60 144001A4 */  bnez      $v0, .L802BF4F4
/* 31FBD4 802BEE64 0000102D */   daddu    $v0, $zero, $zero
.L802BEE68:
/* 31FBD8 802BEE68 3C02802C */  lui       $v0, 0x802c
/* 31FBDC 802BEE6C 8C42FEF4 */  lw        $v0, -0x10c($v0)
/* 31FBE0 802BEE70 144001A0 */  bnez      $v0, .L802BF4F4
/* 31FBE4 802BEE74 0000102D */   daddu    $v0, $zero, $zero
/* 31FBE8 802BEE78 862200A8 */  lh        $v0, 0xa8($s1)
/* 31FBEC 802BEE7C C6260038 */  lwc1      $f6, 0x38($s1)
/* 31FBF0 802BEE80 C6200064 */  lwc1      $f0, 0x64($s1)
/* 31FBF4 802BEE84 C6220040 */  lwc1      $f2, 0x40($s1)
/* 31FBF8 802BEE88 3C014120 */  lui       $at, 0x4120
/* 31FBFC 802BEE8C 44814000 */  mtc1      $at, $f8
/* 31FC00 802BEE90 44822000 */  mtc1      $v0, $f4
/* 31FC04 802BEE94 00000000 */  nop       
/* 31FC08 802BEE98 46802120 */  cvt.s.w   $f4, $f4
/* 31FC0C 802BEE9C 46040000 */  add.s     $f0, $f0, $f4
/* 31FC10 802BEEA0 E7A60020 */  swc1      $f6, 0x20($sp)
/* 31FC14 802BEEA4 E7A20028 */  swc1      $f2, 0x28($sp)
/* 31FC18 802BEEA8 E7A00024 */  swc1      $f0, 0x24($sp)
/* 31FC1C 802BEEAC E7A80010 */  swc1      $f8, 0x10($sp)
/* 31FC20 802BEEB0 C620000C */  lwc1      $f0, 0xc($s1)
/* 31FC24 802BEEB4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31FC28 802BEEB8 862200A8 */  lh        $v0, 0xa8($s1)
/* 31FC2C 802BEEBC 27A50020 */  addiu     $a1, $sp, 0x20
/* 31FC30 802BEEC0 44820000 */  mtc1      $v0, $f0
/* 31FC34 802BEEC4 00000000 */  nop       
/* 31FC38 802BEEC8 46800020 */  cvt.s.w   $f0, $f0
/* 31FC3C 802BEECC E7A00018 */  swc1      $f0, 0x18($sp)
/* 31FC40 802BEED0 862200A6 */  lh        $v0, 0xa6($s1)
/* 31FC44 802BEED4 27A60024 */  addiu     $a2, $sp, 0x24
/* 31FC48 802BEED8 44820000 */  mtc1      $v0, $f0
/* 31FC4C 802BEEDC 00000000 */  nop       
/* 31FC50 802BEEE0 46800020 */  cvt.s.w   $f0, $f0
/* 31FC54 802BEEE4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 31FC58 802BEEE8 8E240080 */  lw        $a0, 0x80($s1)
/* 31FC5C 802BEEEC 0C0376B9 */  jal       func_800DDAE4
/* 31FC60 802BEEF0 27A70028 */   addiu    $a3, $sp, 0x28
/* 31FC64 802BEEF4 10400004 */  beqz      $v0, .L802BEF08
/* 31FC68 802BEEF8 2402FFFF */   addiu    $v0, $zero, -1
/* 31FC6C 802BEEFC 3C028011 */  lui       $v0, 0x8011
/* 31FC70 802BEF00 9442C97A */  lhu       $v0, -0x3686($v0)
/* 31FC74 802BEF04 A6220086 */  sh        $v0, 0x86($s1)
.L802BEF08:
/* 31FC78 802BEF08 A6C20000 */  sh        $v0, ($s6)
/* 31FC7C 802BEF0C 86240086 */  lh        $a0, 0x86($s1)
/* 31FC80 802BEF10 96220086 */  lhu       $v0, 0x86($s1)
/* 31FC84 802BEF14 04800009 */  bltz      $a0, .L802BEF3C
/* 31FC88 802BEF18 30424000 */   andi     $v0, $v0, 0x4000
/* 31FC8C 802BEF1C 14400007 */  bnez      $v0, .L802BEF3C
/* 31FC90 802BEF20 00000000 */   nop      
/* 31FC94 802BEF24 0C016F6A */  jal       get_collider_type_by_id
/* 31FC98 802BEF28 00000000 */   nop      
/* 31FC9C 802BEF2C 304200FF */  andi      $v0, $v0, 0xff
/* 31FCA0 802BEF30 24030004 */  addiu     $v1, $zero, 4
/* 31FCA4 802BEF34 10430011 */  beq       $v0, $v1, .L802BEF7C
/* 31FCA8 802BEF38 AFA20040 */   sw       $v0, 0x40($sp)
.L802BEF3C:
/* 31FCAC 802BEF3C 3C03802C */  lui       $v1, 0x802c
/* 31FCB0 802BEF40 8C63FEE4 */  lw        $v1, -0x11c($v1)
/* 31FCB4 802BEF44 24020002 */  addiu     $v0, $zero, 2
/* 31FCB8 802BEF48 1462016A */  bne       $v1, $v0, .L802BF4F4
/* 31FCBC 802BEF4C 0000102D */   daddu    $v0, $zero, $zero
/* 31FCC0 802BEF50 3C03802C */  lui       $v1, 0x802c
/* 31FCC4 802BEF54 8C63FEE8 */  lw        $v1, -0x118($v1)
/* 31FCC8 802BEF58 24020001 */  addiu     $v0, $zero, 1
/* 31FCCC 802BEF5C 14620165 */  bne       $v1, $v0, .L802BF4F4
/* 31FCD0 802BEF60 0000102D */   daddu    $v0, $zero, $zero
/* 31FCD4 802BEF64 24040294 */  addiu     $a0, $zero, 0x294
/* 31FCD8 802BEF68 0000282D */  daddu     $a1, $zero, $zero
/* 31FCDC 802BEF6C 0C052742 */  jal       play_sound_at_npc
/* 31FCE0 802BEF70 2406FFFC */   addiu    $a2, $zero, -4
/* 31FCE4 802BEF74 080AFD3D */  j         .L802BF4F4
/* 31FCE8 802BEF78 0000102D */   daddu    $v0, $zero, $zero
.L802BEF7C:
/* 31FCEC 802BEF7C 27B00020 */  addiu     $s0, $sp, 0x20
/* 31FCF0 802BEF80 0200202D */  daddu     $a0, $s0, $zero
/* 31FCF4 802BEF84 27B40028 */  addiu     $s4, $sp, 0x28
/* 31FCF8 802BEF88 3C064220 */  lui       $a2, 0x4220
/* 31FCFC 802BEF8C 8E27000C */  lw        $a3, 0xc($s1)
/* 31FD00 802BEF90 C6240038 */  lwc1      $f4, 0x38($s1)
/* 31FD04 802BEF94 C6200064 */  lwc1      $f0, 0x64($s1)
/* 31FD08 802BEF98 3C0142C8 */  lui       $at, 0x42c8
/* 31FD0C 802BEF9C 4481A000 */  mtc1      $at, $f20
/* 31FD10 802BEFA0 C6220040 */  lwc1      $f2, 0x40($s1)
/* 31FD14 802BEFA4 0280282D */  daddu     $a1, $s4, $zero
/* 31FD18 802BEFA8 3C01802C */  lui       $at, 0x802c
/* 31FD1C 802BEFAC AC20FEF0 */  sw        $zero, -0x110($at)
/* 31FD20 802BEFB0 46140000 */  add.s     $f0, $f0, $f20
/* 31FD24 802BEFB4 E7A40020 */  swc1      $f4, 0x20($sp)
/* 31FD28 802BEFB8 E7A20028 */  swc1      $f2, 0x28($sp)
/* 31FD2C 802BEFBC 0C00A7E7 */  jal       add_vec2D_polar
/* 31FD30 802BEFC0 E7A00024 */   swc1     $f0, 0x24($sp)
/* 31FD34 802BEFC4 0200282D */  daddu     $a1, $s0, $zero
/* 31FD38 802BEFC8 27B60030 */  addiu     $s6, $sp, 0x30
/* 31FD3C 802BEFCC 27B30024 */  addiu     $s3, $sp, 0x24
/* 31FD40 802BEFD0 E7B40030 */  swc1      $f20, 0x30($sp)
/* 31FD44 802BEFD4 AFB60010 */  sw        $s6, 0x10($sp)
/* 31FD48 802BEFD8 C620000C */  lwc1      $f0, 0xc($s1)
/* 31FD4C 802BEFDC 0260302D */  daddu     $a2, $s3, $zero
/* 31FD50 802BEFE0 AFA00018 */  sw        $zero, 0x18($sp)
/* 31FD54 802BEFE4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31FD58 802BEFE8 8E240080 */  lw        $a0, 0x80($s1)
/* 31FD5C 802BEFEC 0C0371DE */  jal       func_800DC778
/* 31FD60 802BEFF0 0280382D */   daddu    $a3, $s4, $zero
/* 31FD64 802BEFF4 1040013E */  beqz      $v0, .L802BF4F0
/* 31FD68 802BEFF8 AFA20040 */   sw       $v0, 0x40($sp)
/* 31FD6C 802BEFFC 0200282D */  daddu     $a1, $s0, $zero
/* 31FD70 802BF000 0260302D */  daddu     $a2, $s3, $zero
/* 31FD74 802BF004 86240086 */  lh        $a0, 0x86($s1)
/* 31FD78 802BF008 0C016F84 */  jal       get_collider_center
/* 31FD7C 802BF00C 0280382D */   daddu    $a3, $s4, $zero
/* 31FD80 802BF010 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 31FD84 802BF014 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 31FD88 802BF018 8FA60020 */  lw        $a2, 0x20($sp)
/* 31FD8C 802BF01C 0C00A7B5 */  jal       dist2D
/* 31FD90 802BF020 8FA70028 */   lw       $a3, 0x28($sp)
/* 31FD94 802BF024 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 31FD98 802BF028 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 31FD9C 802BF02C 8FA60020 */  lw        $a2, 0x20($sp)
/* 31FDA0 802BF030 8FA70028 */  lw        $a3, 0x28($sp)
/* 31FDA4 802BF034 0C00A720 */  jal       atan2
/* 31FDA8 802BF038 E7A00030 */   swc1     $f0, 0x30($sp)
/* 31FDAC 802BF03C 3C0140C9 */  lui       $at, 0x40c9
/* 31FDB0 802BF040 34210FD0 */  ori       $at, $at, 0xfd0
/* 31FDB4 802BF044 44811000 */  mtc1      $at, $f2
/* 31FDB8 802BF048 00000000 */  nop       
/* 31FDBC 802BF04C 46020002 */  mul.s     $f0, $f0, $f2
/* 31FDC0 802BF050 00000000 */  nop       
/* 31FDC4 802BF054 27A50038 */  addiu     $a1, $sp, 0x38
/* 31FDC8 802BF058 3C0143B4 */  lui       $at, 0x43b4
/* 31FDCC 802BF05C 44816000 */  mtc1      $at, $f12
/* 31FDD0 802BF060 27A6003C */  addiu     $a2, $sp, 0x3c
/* 31FDD4 802BF064 0C00A82D */  jal       sin_cos_rad
/* 31FDD8 802BF068 460C0303 */   div.s    $f12, $f0, $f12
/* 31FDDC 802BF06C C7A60038 */  lwc1      $f6, 0x38($sp)
/* 31FDE0 802BF070 C7A20030 */  lwc1      $f2, 0x30($sp)
/* 31FDE4 802BF074 46023182 */  mul.s     $f6, $f6, $f2
/* 31FDE8 802BF078 00000000 */  nop       
/* 31FDEC 802BF07C 3C01802C */  lui       $at, 0x802c
/* 31FDF0 802BF080 D420FED0 */  ldc1      $f0, -0x130($at)
/* 31FDF4 802BF084 460031A1 */  cvt.d.s   $f6, $f6
/* 31FDF8 802BF088 46203182 */  mul.d     $f6, $f6, $f0
/* 31FDFC 802BF08C 00000000 */  nop       
/* 31FE00 802BF090 C7A4003C */  lwc1      $f4, 0x3c($sp)
/* 31FE04 802BF094 46022102 */  mul.s     $f4, $f4, $f2
/* 31FE08 802BF098 00000000 */  nop       
/* 31FE0C 802BF09C 46002121 */  cvt.d.s   $f4, $f4
/* 31FE10 802BF0A0 46202102 */  mul.d     $f4, $f4, $f0
/* 31FE14 802BF0A4 00000000 */  nop       
/* 31FE18 802BF0A8 C6220038 */  lwc1      $f2, 0x38($s1)
/* 31FE1C 802BF0AC 460010A1 */  cvt.d.s   $f2, $f2
/* 31FE20 802BF0B0 C6200040 */  lwc1      $f0, 0x40($s1)
/* 31FE24 802BF0B4 46261080 */  add.d     $f2, $f2, $f6
/* 31FE28 802BF0B8 0200282D */  daddu     $a1, $s0, $zero
/* 31FE2C 802BF0BC 46000021 */  cvt.d.s   $f0, $f0
/* 31FE30 802BF0C0 46240001 */  sub.d     $f0, $f0, $f4
/* 31FE34 802BF0C4 E7B40030 */  swc1      $f20, 0x30($sp)
/* 31FE38 802BF0C8 462010A0 */  cvt.s.d   $f2, $f2
/* 31FE3C 802BF0CC 46200020 */  cvt.s.d   $f0, $f0
/* 31FE40 802BF0D0 E7A20020 */  swc1      $f2, 0x20($sp)
/* 31FE44 802BF0D4 E7A00028 */  swc1      $f0, 0x28($sp)
/* 31FE48 802BF0D8 AFB60010 */  sw        $s6, 0x10($sp)
/* 31FE4C 802BF0DC C620000C */  lwc1      $f0, 0xc($s1)
/* 31FE50 802BF0E0 0260302D */  daddu     $a2, $s3, $zero
/* 31FE54 802BF0E4 AFA00018 */  sw        $zero, 0x18($sp)
/* 31FE58 802BF0E8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31FE5C 802BF0EC 8E240080 */  lw        $a0, 0x80($s1)
/* 31FE60 802BF0F0 0C0371DE */  jal       func_800DC778
/* 31FE64 802BF0F4 0280382D */   daddu    $a3, $s4, $zero
/* 31FE68 802BF0F8 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 31FE6C 802BF0FC C7A20020 */  lwc1      $f2, 0x20($sp)
/* 31FE70 802BF100 C7A40028 */  lwc1      $f4, 0x28($sp)
/* 31FE74 802BF104 E6200064 */  swc1      $f0, 0x64($s1)
/* 31FE78 802BF108 E6220060 */  swc1      $f2, 0x60($s1)
/* 31FE7C 802BF10C E6240068 */  swc1      $f4, 0x68($s1)
/* 31FE80 802BF110 C64C0028 */  lwc1      $f12, 0x28($s2)
/* 31FE84 802BF114 C64E0030 */  lwc1      $f14, 0x30($s2)
/* 31FE88 802BF118 44061000 */  mfc1      $a2, $f2
/* 31FE8C 802BF11C 44072000 */  mfc1      $a3, $f4
/* 31FE90 802BF120 0C00A720 */  jal       atan2
/* 31FE94 802BF124 00000000 */   nop      
/* 31FE98 802BF128 E6400080 */  swc1      $f0, 0x80($s2)
/* 31FE9C 802BF12C E620000C */  swc1      $f0, 0xc($s1)
/* 31FEA0 802BF130 C64C0028 */  lwc1      $f12, 0x28($s2)
/* 31FEA4 802BF134 C64E0030 */  lwc1      $f14, 0x30($s2)
/* 31FEA8 802BF138 8E260060 */  lw        $a2, 0x60($s1)
/* 31FEAC 802BF13C 0C00A7B5 */  jal       dist2D
/* 31FEB0 802BF140 8E270068 */   lw       $a3, 0x68($s1)
/* 31FEB4 802BF144 3C0140A0 */  lui       $at, 0x40a0
/* 31FEB8 802BF148 44811000 */  mtc1      $at, $f2
/* 31FEBC 802BF14C 3C013F19 */  lui       $at, 0x3f19
/* 31FEC0 802BF150 3421999A */  ori       $at, $at, 0x999a
/* 31FEC4 802BF154 44812000 */  mtc1      $at, $f4
/* 31FEC8 802BF158 24042081 */  addiu     $a0, $zero, 0x2081
/* 31FECC 802BF15C E622001C */  swc1      $f2, 0x1c($s1)
/* 31FED0 802BF160 46021080 */  add.s     $f2, $f2, $f2
/* 31FED4 802BF164 0000282D */  daddu     $a1, $zero, $zero
/* 31FED8 802BF168 E6240014 */  swc1      $f4, 0x14($s1)
/* 31FEDC 802BF16C 46041083 */  div.s     $f2, $f2, $f4
/* 31FEE0 802BF170 4600140D */  trunc.w.s $f16, $f2
/* 31FEE4 802BF174 44028000 */  mfc1      $v0, $f16
/* 31FEE8 802BF178 00000000 */  nop       
/* 31FEEC 802BF17C A622008E */  sh        $v0, 0x8e($s1)
/* 31FEF0 802BF180 00021400 */  sll       $v0, $v0, 0x10
/* 31FEF4 802BF184 00021403 */  sra       $v0, $v0, 0x10
/* 31FEF8 802BF188 44821000 */  mtc1      $v0, $f2
/* 31FEFC 802BF18C 00000000 */  nop       
/* 31FF00 802BF190 468010A0 */  cvt.s.w   $f2, $f2
/* 31FF04 802BF194 46020083 */  div.s     $f2, $f0, $f2
/* 31FF08 802BF198 E6220018 */  swc1      $f2, 0x18($s1)
/* 31FF0C 802BF19C C6220064 */  lwc1      $f2, 0x64($s1)
/* 31FF10 802BF1A0 C644002C */  lwc1      $f4, 0x2c($s2)
/* 31FF14 802BF1A4 8622008E */  lh        $v0, 0x8e($s1)
/* 31FF18 802BF1A8 46041081 */  sub.s     $f2, $f2, $f4
/* 31FF1C 802BF1AC 44823000 */  mtc1      $v0, $f6
/* 31FF20 802BF1B0 00000000 */  nop       
/* 31FF24 802BF1B4 468031A0 */  cvt.s.w   $f6, $f6
/* 31FF28 802BF1B8 C624001C */  lwc1      $f4, 0x1c($s1)
/* 31FF2C 802BF1BC 46061083 */  div.s     $f2, $f2, $f6
/* 31FF30 802BF1C0 46022100 */  add.s     $f4, $f4, $f2
/* 31FF34 802BF1C4 2406FFFC */  addiu     $a2, $zero, -4
/* 31FF38 802BF1C8 E7A00030 */  swc1      $f0, 0x30($sp)
/* 31FF3C 802BF1CC 0C052742 */  jal       play_sound_at_npc
/* 31FF40 802BF1D0 E624001C */   swc1     $f4, 0x1c($s1)
/* 31FF44 802BF1D4 3C040001 */  lui       $a0, 1
/* 31FF48 802BF1D8 0C037FBF */  jal       func_800DFEFC
/* 31FF4C 802BF1DC 34840006 */   ori      $a0, $a0, 6
/* 31FF50 802BF1E0 0C03802C */  jal       enable_player_shadow
/* 31FF54 802BF1E4 00000000 */   nop      
/* 31FF58 802BF1E8 8E420000 */  lw        $v0, ($s2)
/* 31FF5C 802BF1EC 3C030040 */  lui       $v1, 0x40
/* 31FF60 802BF1F0 00431025 */  or        $v0, $v0, $v1
/* 31FF64 802BF1F4 AE420000 */  sw        $v0, ($s2)
/* 31FF68 802BF1F8 24020003 */  addiu     $v0, $zero, 3
/* 31FF6C 802BF1FC 080AFD3C */  j         .L802BF4F0
/* 31FF70 802BF200 AEA20070 */   sw       $v0, 0x70($s5)
/* 31FF74 802BF204 3C040001 */  lui       $a0, 1
/* 31FF78 802BF208 0C037FBF */  jal       func_800DFEFC
/* 31FF7C 802BF20C 34840007 */   ori      $a0, $a0, 7
/* 31FF80 802BF210 8EA20070 */  lw        $v0, 0x70($s5)
/* 31FF84 802BF214 24420001 */  addiu     $v0, $v0, 1
/* 31FF88 802BF218 AEA20070 */  sw        $v0, 0x70($s5)
/* 31FF8C 802BF21C C622001C */  lwc1      $f2, 0x1c($s1)
/* 31FF90 802BF220 44800000 */  mtc1      $zero, $f0
/* 31FF94 802BF224 00000000 */  nop       
/* 31FF98 802BF228 4600103E */  c.le.s    $f2, $f0
/* 31FF9C 802BF22C 00000000 */  nop       
/* 31FFA0 802BF230 45000006 */  bc1f      .L802BF24C
/* 31FFA4 802BF234 3C040001 */   lui      $a0, 1
/* 31FFA8 802BF238 0C037FBF */  jal       func_800DFEFC
/* 31FFAC 802BF23C 34840008 */   ori      $a0, $a0, 8
/* 31FFB0 802BF240 8EA20070 */  lw        $v0, 0x70($s5)
/* 31FFB4 802BF244 24420001 */  addiu     $v0, $v0, 1
/* 31FFB8 802BF248 AEA20070 */  sw        $v0, 0x70($s5)
.L802BF24C:
/* 31FFBC 802BF24C C62C001C */  lwc1      $f12, 0x1c($s1)
/* 31FFC0 802BF250 44800000 */  mtc1      $zero, $f0
/* 31FFC4 802BF254 00000000 */  nop       
/* 31FFC8 802BF258 4600603E */  c.le.s    $f12, $f0
/* 31FFCC 802BF25C 00000000 */  nop       
/* 31FFD0 802BF260 4500000C */  bc1f      .L802BF294
/* 31FFD4 802BF264 00000000 */   nop      
/* 31FFD8 802BF268 0C038D45 */  jal       func_800E3514
/* 31FFDC 802BF26C 27A50040 */   addiu    $a1, $sp, 0x40
/* 31FFE0 802BF270 8FA20040 */  lw        $v0, 0x40($sp)
/* 31FFE4 802BF274 E7A00024 */  swc1      $f0, 0x24($sp)
/* 31FFE8 802BF278 18400009 */  blez      $v0, .L802BF2A0
/* 31FFEC 802BF27C E640002C */   swc1     $f0, 0x2c($s2)
/* 31FFF0 802BF280 3C040001 */  lui       $a0, 1
/* 31FFF4 802BF284 0C037FBF */  jal       func_800DFEFC
/* 31FFF8 802BF288 34840009 */   ori      $a0, $a0, 9
/* 31FFFC 802BF28C 080AFCA8 */  j         .L802BF2A0
/* 320000 802BF290 00000000 */   nop      
.L802BF294:
/* 320004 802BF294 C640002C */  lwc1      $f0, 0x2c($s2)
/* 320008 802BF298 460C0000 */  add.s     $f0, $f0, $f12
/* 32000C 802BF29C E640002C */  swc1      $f0, 0x2c($s2)
.L802BF2A0:
/* 320010 802BF2A0 C620001C */  lwc1      $f0, 0x1c($s1)
/* 320014 802BF2A4 C6220014 */  lwc1      $f2, 0x14($s1)
/* 320018 802BF2A8 46020001 */  sub.s     $f0, $f0, $f2
/* 32001C 802BF2AC 3C02800B */  lui       $v0, %hi(gCameras)
/* 320020 802BF2B0 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 320024 802BF2B4 E620001C */  swc1      $f0, 0x1c($s1)
/* 320028 802BF2B8 C6400028 */  lwc1      $f0, 0x28($s2)
/* 32002C 802BF2BC C642002C */  lwc1      $f2, 0x2c($s2)
/* 320030 802BF2C0 C6440030 */  lwc1      $f4, 0x30($s2)
/* 320034 802BF2C4 26440028 */  addiu     $a0, $s2, 0x28
/* 320038 802BF2C8 E4400060 */  swc1      $f0, 0x60($v0)
/* 32003C 802BF2CC E4420064 */  swc1      $f2, 0x64($v0)
/* 320040 802BF2D0 E4440068 */  swc1      $f4, 0x68($v0)
/* 320044 802BF2D4 8622008E */  lh        $v0, 0x8e($s1)
/* 320048 802BF2D8 10400007 */  beqz      $v0, .L802BF2F8
/* 32004C 802BF2DC 26450030 */   addiu    $a1, $s2, 0x30
/* 320050 802BF2E0 8E260018 */  lw        $a2, 0x18($s1)
/* 320054 802BF2E4 0C00A7E7 */  jal       add_vec2D_polar
/* 320058 802BF2E8 8E27000C */   lw       $a3, 0xc($s1)
/* 32005C 802BF2EC 9622008E */  lhu       $v0, 0x8e($s1)
/* 320060 802BF2F0 080AFD3B */  j         .L802BF4EC
/* 320064 802BF2F4 2442FFFF */   addiu    $v0, $v0, -1
.L802BF2F8:
/* 320068 802BF2F8 8FA20040 */  lw        $v0, 0x40($sp)
/* 32006C 802BF2FC 0440007C */  bltz      $v0, .L802BF4F0
/* 320070 802BF300 3C03FFBF */   lui      $v1, 0xffbf
/* 320074 802BF304 3463FFFF */  ori       $v1, $v1, 0xffff
/* 320078 802BF308 3C040001 */  lui       $a0, 1
/* 32007C 802BF30C 8E420000 */  lw        $v0, ($s2)
/* 320080 802BF310 34840002 */  ori       $a0, $a0, 2
/* 320084 802BF314 00431024 */  and       $v0, $v0, $v1
/* 320088 802BF318 0C037FBF */  jal       func_800DFEFC
/* 32008C 802BF31C AE420000 */   sw       $v0, ($s2)
/* 320090 802BF320 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 320094 802BF324 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 320098 802BF328 8E260060 */  lw        $a2, 0x60($s1)
/* 32009C 802BF32C 8E220000 */  lw        $v0, ($s1)
/* 3200A0 802BF330 8E270068 */  lw        $a3, 0x68($s1)
/* 3200A4 802BF334 34420040 */  ori       $v0, $v0, 0x40
/* 3200A8 802BF338 0C00A7B5 */  jal       dist2D
/* 3200AC 802BF33C AE220000 */   sw       $v0, ($s1)
/* 3200B0 802BF340 864200B2 */  lh        $v0, 0xb2($s2)
/* 3200B4 802BF344 3C013F00 */  lui       $at, 0x3f00
/* 3200B8 802BF348 44811000 */  mtc1      $at, $f2
/* 3200BC 802BF34C 3C014100 */  lui       $at, 0x4100
/* 3200C0 802BF350 44814000 */  mtc1      $at, $f8
/* 3200C4 802BF354 3C013F80 */  lui       $at, 0x3f80
/* 3200C8 802BF358 44815000 */  mtc1      $at, $f10
/* 3200CC 802BF35C C6260064 */  lwc1      $f6, 0x64($s1)
/* 3200D0 802BF360 44822000 */  mtc1      $v0, $f4
/* 3200D4 802BF364 00000000 */  nop       
/* 3200D8 802BF368 46802120 */  cvt.s.w   $f4, $f4
/* 3200DC 802BF36C 46022102 */  mul.s     $f4, $f4, $f2
/* 3200E0 802BF370 00000000 */  nop       
/* 3200E4 802BF374 C622003C */  lwc1      $f2, 0x3c($s1)
/* 3200E8 802BF378 E628001C */  swc1      $f8, 0x1c($s1)
/* 3200EC 802BF37C 3C014080 */  lui       $at, 0x4080
/* 3200F0 802BF380 44814000 */  mtc1      $at, $f8
/* 3200F4 802BF384 46023181 */  sub.s     $f6, $f6, $f2
/* 3200F8 802BF388 C622001C */  lwc1      $f2, 0x1c($s1)
/* 3200FC 802BF38C E62A0014 */  swc1      $f10, 0x14($s1)
/* 320100 802BF390 46021080 */  add.s     $f2, $f2, $f2
/* 320104 802BF394 E6280018 */  swc1      $f8, 0x18($s1)
/* 320108 802BF398 E7A60024 */  swc1      $f6, 0x24($sp)
/* 32010C 802BF39C 460A1083 */  div.s     $f2, $f2, $f10
/* 320110 802BF3A0 4600140D */  trunc.w.s $f16, $f2
/* 320114 802BF3A4 44028000 */  mfc1      $v0, $f16
/* 320118 802BF3A8 00000000 */  nop       
/* 32011C 802BF3AC A622008E */  sh        $v0, 0x8e($s1)
/* 320120 802BF3B0 00021400 */  sll       $v0, $v0, 0x10
/* 320124 802BF3B4 00021403 */  sra       $v0, $v0, 0x10
/* 320128 802BF3B8 46040000 */  add.s     $f0, $f0, $f4
/* 32012C 802BF3BC 44824000 */  mtc1      $v0, $f8
/* 320130 802BF3C0 00000000 */  nop       
/* 320134 802BF3C4 46804220 */  cvt.s.w   $f8, $f8
/* 320138 802BF3C8 2402000A */  addiu     $v0, $zero, 0xa
/* 32013C 802BF3CC E7A00030 */  swc1      $f0, 0x30($sp)
/* 320140 802BF3D0 8623008E */  lh        $v1, 0x8e($s1)
/* 320144 802BF3D4 C622001C */  lwc1      $f2, 0x1c($s1)
/* 320148 802BF3D8 44832000 */  mtc1      $v1, $f4
/* 32014C 802BF3DC 00000000 */  nop       
/* 320150 802BF3E0 46802120 */  cvt.s.w   $f4, $f4
/* 320154 802BF3E4 46043183 */  div.s     $f6, $f6, $f4
/* 320158 802BF3E8 46061080 */  add.s     $f2, $f2, $f6
/* 32015C 802BF3EC 46080003 */  div.s     $f0, $f0, $f8
/* 320160 802BF3F0 E6200018 */  swc1      $f0, 0x18($s1)
/* 320164 802BF3F4 E622001C */  swc1      $f2, 0x1c($s1)
/* 320168 802BF3F8 080AFD3C */  j         .L802BF4F0
/* 32016C 802BF3FC AEA20070 */   sw       $v0, 0x70($s5)
/* 320170 802BF400 26240038 */  addiu     $a0, $s1, 0x38
/* 320174 802BF404 C624003C */  lwc1      $f4, 0x3c($s1)
/* 320178 802BF408 C620001C */  lwc1      $f0, 0x1c($s1)
/* 32017C 802BF40C 8E260018 */  lw        $a2, 0x18($s1)
/* 320180 802BF410 46002100 */  add.s     $f4, $f4, $f0
/* 320184 802BF414 C6220014 */  lwc1      $f2, 0x14($s1)
/* 320188 802BF418 8E27000C */  lw        $a3, 0xc($s1)
/* 32018C 802BF41C 46020001 */  sub.s     $f0, $f0, $f2
/* 320190 802BF420 26250040 */  addiu     $a1, $s1, 0x40
/* 320194 802BF424 E624003C */  swc1      $f4, 0x3c($s1)
/* 320198 802BF428 0C00A7E7 */  jal       add_vec2D_polar
/* 32019C 802BF42C E620001C */   swc1     $f0, 0x1c($s1)
/* 3201A0 802BF430 8622008E */  lh        $v0, 0x8e($s1)
/* 3201A4 802BF434 9623008E */  lhu       $v1, 0x8e($s1)
/* 3201A8 802BF438 1440002C */  bnez      $v0, .L802BF4EC
/* 3201AC 802BF43C 2462FFFF */   addiu    $v0, $v1, -1
/* 3201B0 802BF440 0C038050 */  jal       enable_player_static_collisions
/* 3201B4 802BF444 00000000 */   nop      
/* 3201B8 802BF448 0C038069 */  jal       enable_player_input
/* 3201BC 802BF44C 00000000 */   nop      
/* 3201C0 802BF450 0C039769 */  jal       set_action_state
/* 3201C4 802BF454 0000202D */   daddu    $a0, $zero, $zero
/* 3201C8 802BF458 0C00EAE8 */  jal       enable_npc_shadow
/* 3201CC 802BF45C 0220202D */   daddu    $a0, $s1, $zero
/* 3201D0 802BF460 0C03BD17 */  jal       clear_partner_move_history
/* 3201D4 802BF464 0220202D */   daddu    $a0, $s1, $zero
/* 3201D8 802BF468 3C040001 */  lui       $a0, 1
/* 3201DC 802BF46C 34840002 */  ori       $a0, $a0, 2
/* 3201E0 802BF470 0000282D */  daddu     $a1, $zero, $zero
/* 3201E4 802BF474 00A0302D */  daddu     $a2, $a1, $zero
/* 3201E8 802BF478 00A0382D */  daddu     $a3, $a1, $zero
/* 3201EC 802BF47C 8E220000 */  lw        $v0, ($s1)
/* 3201F0 802BF480 3C088007 */  lui       $t0, %hi(gGameStatusPtr)
/* 3201F4 802BF484 8D08419C */  lw        $t0, %lo(gGameStatusPtr)($t0)
/* 3201F8 802BF488 2403FFF7 */  addiu     $v1, $zero, -9
/* 3201FC 802BF48C 3C01802C */  lui       $at, 0x802c
/* 320200 802BF490 AC20FEEC */  sw        $zero, -0x114($at)
/* 320204 802BF494 00431024 */  and       $v0, $v0, $v1
/* 320208 802BF498 34420200 */  ori       $v0, $v0, 0x200
/* 32020C 802BF49C 2403FFBF */  addiu     $v1, $zero, -0x41
/* 320210 802BF4A0 00431024 */  and       $v0, $v0, $v1
/* 320214 802BF4A4 AE220000 */  sw        $v0, ($s1)
/* 320218 802BF4A8 A100007D */  sb        $zero, 0x7d($t0)
/* 32021C 802BF4AC A2800000 */  sb        $zero, ($s4)
/* 320220 802BF4B0 A2800003 */  sb        $zero, 3($s4)
/* 320224 802BF4B4 AFA00010 */  sw        $zero, 0x10($sp)
/* 320228 802BF4B8 AFA00014 */  sw        $zero, 0x14($sp)
/* 32022C 802BF4BC 0C0B77FE */  jal       func_802DDFF8
/* 320230 802BF4C0 AFA00018 */   sw       $zero, 0x18($sp)
/* 320234 802BF4C4 0220202D */  daddu     $a0, $s1, $zero
/* 320238 802BF4C8 0000282D */  daddu     $a1, $zero, $zero
/* 32023C 802BF4CC 00A0302D */  daddu     $a2, $a1, $zero
/* 320240 802BF4D0 00A0382D */  daddu     $a3, $a1, $zero
/* 320244 802BF4D4 AFA00010 */  sw        $zero, 0x10($sp)
/* 320248 802BF4D8 AFA00014 */  sw        $zero, 0x14($sp)
/* 32024C 802BF4DC 0C00F589 */  jal       func_8003D624
/* 320250 802BF4E0 AFA00018 */   sw       $zero, 0x18($sp)
/* 320254 802BF4E4 080AFD3D */  j         .L802BF4F4
/* 320258 802BF4E8 24020001 */   addiu    $v0, $zero, 1
.L802BF4EC:
/* 32025C 802BF4EC A622008E */  sh        $v0, 0x8e($s1)
.L802BF4F0:
/* 320260 802BF4F0 0000102D */  daddu     $v0, $zero, $zero
.L802BF4F4:
/* 320264 802BF4F4 8FBF0064 */  lw        $ra, 0x64($sp)
/* 320268 802BF4F8 8FB60060 */  lw        $s6, 0x60($sp)
/* 32026C 802BF4FC 8FB5005C */  lw        $s5, 0x5c($sp)
/* 320270 802BF500 8FB40058 */  lw        $s4, 0x58($sp)
/* 320274 802BF504 8FB30054 */  lw        $s3, 0x54($sp)
/* 320278 802BF508 8FB20050 */  lw        $s2, 0x50($sp)
/* 32027C 802BF50C 8FB1004C */  lw        $s1, 0x4c($sp)
/* 320280 802BF510 8FB00048 */  lw        $s0, 0x48($sp)
/* 320284 802BF514 D7B40068 */  ldc1      $f20, 0x68($sp)
/* 320288 802BF518 03E00008 */  jr        $ra
/* 32028C 802BF51C 27BD0070 */   addiu    $sp, $sp, 0x70
