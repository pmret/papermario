.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_model_data
/* AC444 80115D44 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AC448 80115D48 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AC44C 80115D4C 80420070 */  lb        $v0, 0x70($v0)
/* AC450 80115D50 1440002C */  bnez      $v0, .L80115E04
/* AC454 80115D54 00000000 */   nop      
/* AC458 80115D58 3C028015 */  lui       $v0, %hi(gWorldModelList)
/* AC45C 80115D5C 24421770 */  addiu     $v0, $v0, %lo(gWorldModelList)
/* AC460 80115D60 3C018015 */  lui       $at, %hi(gCurrentModelListPtr)
/* AC464 80115D64 AC2212CC */  sw        $v0, %lo(gCurrentModelListPtr)($at)
/* AC468 80115D68 3C028015 */  lui       $v0, %hi(D_80151F70)
/* AC46C 80115D6C 24421F70 */  addiu     $v0, $v0, %lo(D_80151F70)
/* AC470 80115D70 3C018015 */  lui       $at, %hi(D_801512E0)
/* AC474 80115D74 AC2212E0 */  sw        $v0, %lo(D_801512E0)($at)
/* AC478 80115D78 3C028015 */  lui       $v0, %hi(gWorldModelSpecialDls)
/* AC47C 80115D7C 24421F90 */  addiu     $v0, $v0, %lo(gWorldModelSpecialDls)
/* AC480 80115D80 3C018015 */  lui       $at, %hi(gCurrentModelSpecialDlsPtr)
/* AC484 80115D84 AC2212E8 */  sw        $v0, %lo(gCurrentModelSpecialDlsPtr)($at)
/* AC488 80115D88 3C028015 */  lui       $v0, %hi(D_80152090)
/* AC48C 80115D8C 24422090 */  addiu     $v0, $v0, %lo(D_80152090)
/* AC490 80115D90 3C018015 */  lui       $at, %hi(D_801512B8)
/* AC494 80115D94 AC2212B8 */  sw        $v0, %lo(D_801512B8)($at)
/* AC498 80115D98 3C028015 */  lui       $v0, %hi(D_80152214)
/* AC49C 80115D9C 24422214 */  addiu     $v0, $v0, %lo(D_80152214)
/* AC4A0 80115DA0 3C018015 */  lui       $at, %hi(D_801512FC)
/* AC4A4 80115DA4 AC2212FC */  sw        $v0, %lo(D_801512FC)($at)
/* AC4A8 80115DA8 3C028015 */  lui       $v0, %hi(D_80152190)
/* AC4AC 80115DAC 24422190 */  addiu     $v0, $v0, %lo(D_80152190)
/* AC4B0 80115DB0 3C018015 */  lui       $at, %hi(D_80152210)
/* AC4B4 80115DB4 AC222210 */  sw        $v0, %lo(D_80152210)($at)
/* AC4B8 80115DB8 3C028015 */  lui       $v0, %hi(D_80152220)
/* AC4BC 80115DBC 24422220 */  addiu     $v0, $v0, %lo(D_80152220)
/* AC4C0 80115DC0 3C01800A */  lui       $at, %hi(D_8009A5F4)
/* AC4C4 80115DC4 AC22A5F4 */  sw        $v0, %lo(D_8009A5F4)($at)
/* AC4C8 80115DC8 3C028015 */  lui       $v0, %hi(D_80153220)
/* AC4CC 80115DCC 24423220 */  addiu     $v0, $v0, %lo(D_80153220)
/* AC4D0 80115DD0 3C018015 */  lui       $at, %hi(D_801512F0)
/* AC4D4 80115DD4 AC2212F0 */  sw        $v0, %lo(D_801512F0)($at)
/* AC4D8 80115DD8 3C028015 */  lui       $v0, %hi(D_80153228)
/* AC4DC 80115DDC 24423228 */  addiu     $v0, $v0, %lo(D_80153228)
/* AC4E0 80115DE0 3C018015 */  lui       $at, %hi(D_8014B74C)
/* AC4E4 80115DE4 A020B74C */  sb        $zero, %lo(D_8014B74C)($at)
/* AC4E8 80115DE8 3C018015 */  lui       $at, %hi(D_8014B74D)
/* AC4EC 80115DEC A020B74D */  sb        $zero, %lo(D_8014B74D)($at)
/* AC4F0 80115DF0 3C018015 */  lui       $at, %hi(D_8014B74E)
/* AC4F4 80115DF4 A020B74E */  sb        $zero, %lo(D_8014B74E)($at)
/* AC4F8 80115DF8 3C018015 */  lui       $at, %hi(D_8014B74F)
/* AC4FC 80115DFC 080457A3 */  j         .L80115E8C
/* AC500 80115E00 A020B74F */   sb       $zero, %lo(D_8014B74F)($at)
.L80115E04:
/* AC504 80115E04 3C028015 */  lui       $v0, %hi(gBattleModelList)
/* AC508 80115E08 24421B70 */  addiu     $v0, $v0, %lo(gBattleModelList)
/* AC50C 80115E0C 3C018015 */  lui       $at, %hi(gCurrentModelListPtr)
/* AC510 80115E10 AC2212CC */  sw        $v0, %lo(gCurrentModelListPtr)($at)
/* AC514 80115E14 3C028015 */  lui       $v0, %hi(D_80151F80)
/* AC518 80115E18 24421F80 */  addiu     $v0, $v0, %lo(D_80151F80)
/* AC51C 80115E1C 3C018015 */  lui       $at, %hi(D_801512E0)
/* AC520 80115E20 AC2212E0 */  sw        $v0, %lo(D_801512E0)($at)
/* AC524 80115E24 3C028015 */  lui       $v0, %hi(gBattleModelSpecialDls)
/* AC528 80115E28 24422010 */  addiu     $v0, $v0, %lo(gBattleModelSpecialDls)
/* AC52C 80115E2C 3C018015 */  lui       $at, %hi(gCurrentModelSpecialDlsPtr)
/* AC530 80115E30 AC2212E8 */  sw        $v0, %lo(gCurrentModelSpecialDlsPtr)($at)
/* AC534 80115E34 3C028015 */  lui       $v0, %hi(D_80152110)
/* AC538 80115E38 24422110 */  addiu     $v0, $v0, %lo(D_80152110)
/* AC53C 80115E3C 3C018015 */  lui       $at, %hi(D_801512B8)
/* AC540 80115E40 AC2212B8 */  sw        $v0, %lo(D_801512B8)($at)
/* AC544 80115E44 3C028015 */  lui       $v0, %hi(D_80152218)
/* AC548 80115E48 24422218 */  addiu     $v0, $v0, %lo(D_80152218)
/* AC54C 80115E4C 3C018015 */  lui       $at, %hi(D_801512FC)
/* AC550 80115E50 AC2212FC */  sw        $v0, %lo(D_801512FC)($at)
/* AC554 80115E54 3C028015 */  lui       $v0, %hi(D_801521D0)
/* AC558 80115E58 244221D0 */  addiu     $v0, $v0, %lo(D_801521D0)
/* AC55C 80115E5C 3C018015 */  lui       $at, %hi(D_80152210)
/* AC560 80115E60 AC222210 */  sw        $v0, %lo(D_80152210)($at)
/* AC564 80115E64 3C028015 */  lui       $v0, %hi(D_80152A20)
/* AC568 80115E68 24422A20 */  addiu     $v0, $v0, %lo(D_80152A20)
/* AC56C 80115E6C 3C01800A */  lui       $at, %hi(D_8009A5F4)
/* AC570 80115E70 AC22A5F4 */  sw        $v0, %lo(D_8009A5F4)($at)
/* AC574 80115E74 3C028015 */  lui       $v0, %hi(D_80153221)
/* AC578 80115E78 24423221 */  addiu     $v0, $v0, %lo(D_80153221)
/* AC57C 80115E7C 3C018015 */  lui       $at, %hi(D_801512F0)
/* AC580 80115E80 AC2212F0 */  sw        $v0, %lo(D_801512F0)($at)
/* AC584 80115E84 3C028015 */  lui       $v0, %hi(D_80153248)
/* AC588 80115E88 24423248 */  addiu     $v0, $v0, %lo(D_80153248)
.L80115E8C:
/* AC58C 80115E8C 3C018015 */  lui       $at, %hi(D_80153264)
/* AC590 80115E90 AC223264 */  sw        $v0, %lo(D_80153264)($at)
/* AC594 80115E94 3C028015 */  lui       $v0, %hi(gCurrentModelListPtr)
/* AC598 80115E98 8C4212CC */  lw        $v0, %lo(gCurrentModelListPtr)($v0)
/* AC59C 80115E9C 240400FF */  addiu     $a0, $zero, 0xff
/* AC5A0 80115EA0 244203FC */  addiu     $v0, $v0, 0x3fc
.L80115EA4:
/* AC5A4 80115EA4 AC400000 */  sw        $zero, ($v0)
/* AC5A8 80115EA8 2484FFFF */  addiu     $a0, $a0, -1
/* AC5AC 80115EAC 0481FFFD */  bgez      $a0, .L80115EA4
/* AC5B0 80115EB0 2442FFFC */   addiu    $v0, $v0, -4
/* AC5B4 80115EB4 3C028015 */  lui       $v0, %hi(D_801512E0)
/* AC5B8 80115EB8 8C4212E0 */  lw        $v0, %lo(D_801512E0)($v0)
/* AC5BC 80115EBC 24040003 */  addiu     $a0, $zero, 3
/* AC5C0 80115EC0 2442000C */  addiu     $v0, $v0, 0xc
.L80115EC4:
/* AC5C4 80115EC4 AC400000 */  sw        $zero, ($v0)
/* AC5C8 80115EC8 2484FFFF */  addiu     $a0, $a0, -1
/* AC5CC 80115ECC 0481FFFD */  bgez      $a0, .L80115EC4
/* AC5D0 80115ED0 2442FFFC */   addiu    $v0, $v0, -4
/* AC5D4 80115ED4 0000202D */  daddu     $a0, $zero, $zero
/* AC5D8 80115ED8 3C058015 */  lui       $a1, %hi(D_801512B8)
/* AC5DC 80115EDC 8CA512B8 */  lw        $a1, %lo(D_801512B8)($a1)
/* AC5E0 80115EE0 3C038015 */  lui       $v1, %hi(gCurrentModelSpecialDlsPtr)
/* AC5E4 80115EE4 8C6312E8 */  lw        $v1, %lo(gCurrentModelSpecialDlsPtr)($v1)
.L80115EE8:
/* AC5E8 80115EE8 AC600000 */  sw        $zero, ($v1)
/* AC5EC 80115EEC ACA00000 */  sw        $zero, ($a1)
/* AC5F0 80115EF0 24A50004 */  addiu     $a1, $a1, 4
/* AC5F4 80115EF4 24840001 */  addiu     $a0, $a0, 1
/* AC5F8 80115EF8 28820020 */  slti      $v0, $a0, 0x20
/* AC5FC 80115EFC 1440FFFA */  bnez      $v0, .L80115EE8
/* AC600 80115F00 24630004 */   addiu    $v1, $v1, 4
/* AC604 80115F04 0000202D */  daddu     $a0, $zero, $zero
/* AC608 80115F08 3C05800A */  lui       $a1, %hi(D_8009A5F4)
/* AC60C 80115F0C 24A5A5F4 */  addiu     $a1, $a1, %lo(D_8009A5F4)
/* AC610 80115F10 3C028015 */  lui       $v0, %hi(D_801512FC)
/* AC614 80115F14 8C4212FC */  lw        $v0, %lo(D_801512FC)($v0)
/* AC618 80115F18 240600FF */  addiu     $a2, $zero, 0xff
/* AC61C 80115F1C AC400000 */  sw        $zero, ($v0)
.L80115F20:
/* AC620 80115F20 8CA20000 */  lw        $v0, ($a1)
/* AC624 80115F24 00041880 */  sll       $v1, $a0, 2
/* AC628 80115F28 00621021 */  addu      $v0, $v1, $v0
/* AC62C 80115F2C A0460000 */  sb        $a2, ($v0)
/* AC630 80115F30 8CA20000 */  lw        $v0, ($a1)
/* AC634 80115F34 00621021 */  addu      $v0, $v1, $v0
/* AC638 80115F38 A0400001 */  sb        $zero, 1($v0)
/* AC63C 80115F3C 8CA20000 */  lw        $v0, ($a1)
/* AC640 80115F40 24840001 */  addiu     $a0, $a0, 1
/* AC644 80115F44 00621821 */  addu      $v1, $v1, $v0
/* AC648 80115F48 28820200 */  slti      $v0, $a0, 0x200
/* AC64C 80115F4C 1440FFF4 */  bnez      $v0, .L80115F20
/* AC650 80115F50 A0600002 */   sb       $zero, 2($v1)
/* AC654 80115F54 0000202D */  daddu     $a0, $zero, $zero
/* AC658 80115F58 3C088015 */  lui       $t0, %hi(D_80153268)
/* AC65C 80115F5C 25083268 */  addiu     $t0, $t0, %lo(D_80153268)
/* AC660 80115F60 3C078015 */  lui       $a3, %hi(D_801532A8)
/* AC664 80115F64 24E732A8 */  addiu     $a3, $a3, %lo(D_801532A8)
/* AC668 80115F68 3C068015 */  lui       $a2, %hi(D_801532E8)
/* AC66C 80115F6C 24C632E8 */  addiu     $a2, $a2, %lo(D_801532E8)
/* AC670 80115F70 3C028015 */  lui       $v0, %hi(D_801512F0)
/* AC674 80115F74 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* AC678 80115F78 3C058015 */  lui       $a1, %hi(D_80153328)
/* AC67C 80115F7C 24A53328 */  addiu     $a1, $a1, %lo(D_80153328)
/* AC680 80115F80 A0400000 */  sb        $zero, ($v0)
/* AC684 80115F84 3C038015 */  lui       $v1, %hi(D_80153264)
/* AC688 80115F88 8C633264 */  lw        $v1, %lo(D_80153264)($v1)
/* AC68C 80115F8C 2402000A */  addiu     $v0, $zero, 0xa
/* AC690 80115F90 AC620004 */  sw        $v0, 4($v1)
/* AC694 80115F94 AC620008 */  sw        $v0, 8($v1)
/* AC698 80115F98 AC62000C */  sw        $v0, 0xc($v1)
/* AC69C 80115F9C 240203B6 */  addiu     $v0, $zero, 0x3b6
/* AC6A0 80115FA0 AC620014 */  sw        $v0, 0x14($v1)
/* AC6A4 80115FA4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* AC6A8 80115FA8 AC600000 */  sw        $zero, ($v1)
/* AC6AC 80115FAC AC600010 */  sw        $zero, 0x10($v1)
/* AC6B0 80115FB0 AC620018 */  sw        $v0, 0x18($v1)
.L80115FB4:
/* AC6B4 80115FB4 ACA00000 */  sw        $zero, ($a1)
/* AC6B8 80115FB8 ACC00000 */  sw        $zero, ($a2)
/* AC6BC 80115FBC ACE00000 */  sw        $zero, ($a3)
/* AC6C0 80115FC0 AD000000 */  sw        $zero, ($t0)
/* AC6C4 80115FC4 25080004 */  addiu     $t0, $t0, 4
/* AC6C8 80115FC8 24E70004 */  addiu     $a3, $a3, 4
/* AC6CC 80115FCC 24C60004 */  addiu     $a2, $a2, 4
/* AC6D0 80115FD0 24840001 */  addiu     $a0, $a0, 1
/* AC6D4 80115FD4 28820010 */  slti      $v0, $a0, 0x10
/* AC6D8 80115FD8 1440FFF6 */  bnez      $v0, .L80115FB4
/* AC6DC 80115FDC 24A50004 */   addiu    $a1, $a1, 4
/* AC6E0 80115FE0 03E00008 */  jr        $ra
/* AC6E4 80115FE4 00000000 */   nop      
