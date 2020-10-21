.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BD4_9FC3C4
/* 9FC3C4 80241BD4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 9FC3C8 80241BD8 AFB3005C */  sw        $s3, 0x5c($sp)
/* 9FC3CC 80241BDC 0080982D */  daddu     $s3, $a0, $zero
/* 9FC3D0 80241BE0 AFBF0068 */  sw        $ra, 0x68($sp)
/* 9FC3D4 80241BE4 AFB50064 */  sw        $s5, 0x64($sp)
/* 9FC3D8 80241BE8 AFB40060 */  sw        $s4, 0x60($sp)
/* 9FC3DC 80241BEC AFB20058 */  sw        $s2, 0x58($sp)
/* 9FC3E0 80241BF0 AFB10054 */  sw        $s1, 0x54($sp)
/* 9FC3E4 80241BF4 AFB00050 */  sw        $s0, 0x50($sp)
/* 9FC3E8 80241BF8 8E710148 */  lw        $s1, 0x148($s3)
/* 9FC3EC 80241BFC 86240008 */  lh        $a0, 8($s1)
/* 9FC3F0 80241C00 0C00EABB */  jal       get_npc_unsafe
/* 9FC3F4 80241C04 00A0802D */   daddu    $s0, $a1, $zero
/* 9FC3F8 80241C08 8E63000C */  lw        $v1, 0xc($s3)
/* 9FC3FC 80241C0C 0260202D */  daddu     $a0, $s3, $zero
/* 9FC400 80241C10 8C650000 */  lw        $a1, ($v1)
/* 9FC404 80241C14 0C0B1EAF */  jal       get_variable
/* 9FC408 80241C18 0040902D */   daddu    $s2, $v0, $zero
/* 9FC40C 80241C1C AFA00028 */  sw        $zero, 0x28($sp)
/* 9FC410 80241C20 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC414 80241C24 8C630094 */  lw        $v1, 0x94($v1)
/* 9FC418 80241C28 AFA3002C */  sw        $v1, 0x2c($sp)
/* 9FC41C 80241C2C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC420 80241C30 8C630080 */  lw        $v1, 0x80($v1)
/* 9FC424 80241C34 AFA30030 */  sw        $v1, 0x30($sp)
/* 9FC428 80241C38 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC42C 80241C3C 8C630088 */  lw        $v1, 0x88($v1)
/* 9FC430 80241C40 AFA30034 */  sw        $v1, 0x34($sp)
/* 9FC434 80241C44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC438 80241C48 8C63008C */  lw        $v1, 0x8c($v1)
/* 9FC43C 80241C4C 27B50028 */  addiu     $s5, $sp, 0x28
/* 9FC440 80241C50 AFA30038 */  sw        $v1, 0x38($sp)
/* 9FC444 80241C54 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FC448 80241C58 3C0142C8 */  lui       $at, 0x42c8
/* 9FC44C 80241C5C 44810000 */  mtc1      $at, $f0
/* 9FC450 80241C60 8C630090 */  lw        $v1, 0x90($v1)
/* 9FC454 80241C64 0040A02D */  daddu     $s4, $v0, $zero
/* 9FC458 80241C68 E7A00040 */  swc1      $f0, 0x40($sp)
/* 9FC45C 80241C6C A7A00044 */  sh        $zero, 0x44($sp)
/* 9FC460 80241C70 12000007 */  beqz      $s0, .L80241C90
/* 9FC464 80241C74 AFA3003C */   sw       $v1, 0x3c($sp)
/* 9FC468 80241C78 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FC46C 80241C7C 864300A8 */  lh        $v1, 0xa8($s2)
/* 9FC470 80241C80 34420008 */  ori       $v0, $v0, 8
/* 9FC474 80241C84 AE230084 */  sw        $v1, 0x84($s1)
/* 9FC478 80241C88 08090728 */  j         .L80241CA0
/* 9FC47C 80241C8C AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241C90:
/* 9FC480 80241C90 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FC484 80241C94 30420004 */  andi      $v0, $v0, 4
/* 9FC488 80241C98 10400048 */  beqz      $v0, .L80241DBC
/* 9FC48C 80241C9C 00000000 */   nop      
.L80241CA0:
/* 9FC490 80241CA0 A640008E */  sh        $zero, 0x8e($s2)
/* 9FC494 80241CA4 AE600070 */  sw        $zero, 0x70($s3)
/* 9FC498 80241CA8 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9FC49C 80241CAC 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9FC4A0 80241CB0 A2200007 */  sb        $zero, 7($s1)
/* 9FC4A4 80241CB4 8E420000 */  lw        $v0, ($s2)
/* 9FC4A8 80241CB8 8C630000 */  lw        $v1, ($v1)
/* 9FC4AC 80241CBC 00441024 */  and       $v0, $v0, $a0
/* 9FC4B0 80241CC0 AE420000 */  sw        $v0, ($s2)
/* 9FC4B4 80241CC4 AE430028 */  sw        $v1, 0x28($s2)
/* 9FC4B8 80241CC8 96220086 */  lhu       $v0, 0x86($s1)
/* 9FC4BC 80241CCC A64200A8 */  sh        $v0, 0xa8($s2)
/* 9FC4C0 80241CD0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9FC4C4 80241CD4 A22000B5 */  sb        $zero, 0xb5($s1)
/* 9FC4C8 80241CD8 AE20008C */  sw        $zero, 0x8c($s1)
/* 9FC4CC 80241CDC 8C420098 */  lw        $v0, 0x98($v0)
/* 9FC4D0 80241CE0 14400006 */  bnez      $v0, .L80241CFC
/* 9FC4D4 80241CE4 2403FDFF */   addiu    $v1, $zero, -0x201
/* 9FC4D8 80241CE8 8E420000 */  lw        $v0, ($s2)
/* 9FC4DC 80241CEC 2403FFF7 */  addiu     $v1, $zero, -9
/* 9FC4E0 80241CF0 34420200 */  ori       $v0, $v0, 0x200
/* 9FC4E4 80241CF4 08090742 */  j         .L80241D08
/* 9FC4E8 80241CF8 00431024 */   and      $v0, $v0, $v1
.L80241CFC:
/* 9FC4EC 80241CFC 8E420000 */  lw        $v0, ($s2)
/* 9FC4F0 80241D00 00431024 */  and       $v0, $v0, $v1
/* 9FC4F4 80241D04 34420008 */  ori       $v0, $v0, 8
.L80241D08:
/* 9FC4F8 80241D08 AE420000 */  sw        $v0, ($s2)
/* 9FC4FC 80241D0C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FC500 80241D10 30420004 */  andi      $v0, $v0, 4
/* 9FC504 80241D14 1040001E */  beqz      $v0, .L80241D90
/* 9FC508 80241D18 24040002 */   addiu    $a0, $zero, 2
/* 9FC50C 80241D1C 0240282D */  daddu     $a1, $s2, $zero
/* 9FC510 80241D20 0000302D */  daddu     $a2, $zero, $zero
/* 9FC514 80241D24 24020063 */  addiu     $v0, $zero, 0x63
/* 9FC518 80241D28 AE620070 */  sw        $v0, 0x70($s3)
/* 9FC51C 80241D2C AE600074 */  sw        $zero, 0x74($s3)
/* 9FC520 80241D30 864300A8 */  lh        $v1, 0xa8($s2)
/* 9FC524 80241D34 3C013F80 */  lui       $at, 0x3f80
/* 9FC528 80241D38 44810000 */  mtc1      $at, $f0
/* 9FC52C 80241D3C 3C014000 */  lui       $at, 0x4000
/* 9FC530 80241D40 44811000 */  mtc1      $at, $f2
/* 9FC534 80241D44 3C01C1A0 */  lui       $at, 0xc1a0
/* 9FC538 80241D48 44812000 */  mtc1      $at, $f4
/* 9FC53C 80241D4C 24020028 */  addiu     $v0, $zero, 0x28
/* 9FC540 80241D50 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9FC544 80241D54 44833000 */  mtc1      $v1, $f6
/* 9FC548 80241D58 00000000 */  nop       
/* 9FC54C 80241D5C 468031A0 */  cvt.s.w   $f6, $f6
/* 9FC550 80241D60 44073000 */  mfc1      $a3, $f6
/* 9FC554 80241D64 27A20048 */  addiu     $v0, $sp, 0x48
/* 9FC558 80241D68 AFA20020 */  sw        $v0, 0x20($sp)
/* 9FC55C 80241D6C E7A00010 */  swc1      $f0, 0x10($sp)
/* 9FC560 80241D70 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9FC564 80241D74 0C01BFA4 */  jal       fx_emote
/* 9FC568 80241D78 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9FC56C 80241D7C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9FC570 80241D80 2403FFFB */  addiu     $v1, $zero, -5
/* 9FC574 80241D84 00431024 */  and       $v0, $v0, $v1
/* 9FC578 80241D88 0809076F */  j         .L80241DBC
/* 9FC57C 80241D8C AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241D90:
/* 9FC580 80241D90 8E220000 */  lw        $v0, ($s1)
/* 9FC584 80241D94 3C034000 */  lui       $v1, 0x4000
/* 9FC588 80241D98 00431024 */  and       $v0, $v0, $v1
/* 9FC58C 80241D9C 10400007 */  beqz      $v0, .L80241DBC
/* 9FC590 80241DA0 3C03BFFF */   lui      $v1, 0xbfff
/* 9FC594 80241DA4 2402000C */  addiu     $v0, $zero, 0xc
/* 9FC598 80241DA8 AE620070 */  sw        $v0, 0x70($s3)
/* 9FC59C 80241DAC 8E220000 */  lw        $v0, ($s1)
/* 9FC5A0 80241DB0 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9FC5A4 80241DB4 00431024 */  and       $v0, $v0, $v1
/* 9FC5A8 80241DB8 AE220000 */  sw        $v0, ($s1)
.L80241DBC:
/* 9FC5AC 80241DBC 8E630070 */  lw        $v1, 0x70($s3)
/* 9FC5B0 80241DC0 2C620064 */  sltiu     $v0, $v1, 0x64
/* 9FC5B4 80241DC4 1040003A */  beqz      $v0, .L80241EB0
/* 9FC5B8 80241DC8 00031080 */   sll      $v0, $v1, 2
/* 9FC5BC 80241DCC 3C018024 */  lui       $at, 0x8024
/* 9FC5C0 80241DD0 00220821 */  addu      $at, $at, $v0
/* 9FC5C4 80241DD4 8C225C70 */  lw        $v0, 0x5c70($at)
/* 9FC5C8 80241DD8 00400008 */  jr        $v0
/* 9FC5CC 80241DDC 00000000 */   nop      
/* 9FC5D0 80241DE0 0260202D */  daddu     $a0, $s3, $zero
/* 9FC5D4 80241DE4 0280282D */  daddu     $a1, $s4, $zero
/* 9FC5D8 80241DE8 0C090351 */  jal       func_80240D44_9FB534
/* 9FC5DC 80241DEC 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC5E0 80241DF0 96220086 */  lhu       $v0, 0x86($s1)
/* 9FC5E4 80241DF4 A64200A8 */  sh        $v0, 0xa8($s2)
/* 9FC5E8 80241DF8 0260202D */  daddu     $a0, $s3, $zero
/* 9FC5EC 80241DFC 0280282D */  daddu     $a1, $s4, $zero
/* 9FC5F0 80241E00 0C0903A7 */  jal       func_80240E9C_9FB68C
/* 9FC5F4 80241E04 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC5F8 80241E08 080907AC */  j         .L80241EB0
/* 9FC5FC 80241E0C 00000000 */   nop      
/* 9FC600 80241E10 0260202D */  daddu     $a0, $s3, $zero
/* 9FC604 80241E14 0280282D */  daddu     $a1, $s4, $zero
/* 9FC608 80241E18 0C090451 */  jal       func_80241144_9FB934
/* 9FC60C 80241E1C 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC610 80241E20 0260202D */  daddu     $a0, $s3, $zero
/* 9FC614 80241E24 0280282D */  daddu     $a1, $s4, $zero
/* 9FC618 80241E28 0C090481 */  jal       func_80241204_9FB9F4
/* 9FC61C 80241E2C 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC620 80241E30 080907AC */  j         .L80241EB0
/* 9FC624 80241E34 00000000 */   nop      
/* 9FC628 80241E38 0260202D */  daddu     $a0, $s3, $zero
/* 9FC62C 80241E3C 0280282D */  daddu     $a1, $s4, $zero
/* 9FC630 80241E40 0C0904F0 */  jal       func_802413C0_9FBBB0
/* 9FC634 80241E44 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC638 80241E48 080907AC */  j         .L80241EB0
/* 9FC63C 80241E4C 00000000 */   nop      
/* 9FC640 80241E50 0260202D */  daddu     $a0, $s3, $zero
/* 9FC644 80241E54 0280282D */  daddu     $a1, $s4, $zero
/* 9FC648 80241E58 0C09015C */  jal       func_80240570_9FAD60
/* 9FC64C 80241E5C 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC650 80241E60 0260202D */  daddu     $a0, $s3, $zero
/* 9FC654 80241E64 0280282D */  daddu     $a1, $s4, $zero
/* 9FC658 80241E68 0C09017B */  jal       func_802405EC_9FADDC
/* 9FC65C 80241E6C 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC660 80241E70 080907AC */  j         .L80241EB0
/* 9FC664 80241E74 00000000 */   nop      
/* 9FC668 80241E78 0260202D */  daddu     $a0, $s3, $zero
/* 9FC66C 80241E7C 0280282D */  daddu     $a1, $s4, $zero
/* 9FC670 80241E80 0C0901C8 */  jal       func_80240720_9FAF10
/* 9FC674 80241E84 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC678 80241E88 080907AC */  j         .L80241EB0
/* 9FC67C 80241E8C 00000000 */   nop      
/* 9FC680 80241E90 0260202D */  daddu     $a0, $s3, $zero
/* 9FC684 80241E94 0280282D */  daddu     $a1, $s4, $zero
/* 9FC688 80241E98 0C090221 */  jal       func_80240884_9FB074
/* 9FC68C 80241E9C 02A0302D */   daddu    $a2, $s5, $zero
/* 9FC690 80241EA0 080907AC */  j         .L80241EB0
/* 9FC694 80241EA4 00000000 */   nop      
/* 9FC698 80241EA8 0C0129CF */  jal       func_8004A73C
/* 9FC69C 80241EAC 0260202D */   daddu    $a0, $s3, $zero
.L80241EB0:
/* 9FC6A0 80241EB0 8FBF0068 */  lw        $ra, 0x68($sp)
/* 9FC6A4 80241EB4 8FB50064 */  lw        $s5, 0x64($sp)
/* 9FC6A8 80241EB8 8FB40060 */  lw        $s4, 0x60($sp)
/* 9FC6AC 80241EBC 8FB3005C */  lw        $s3, 0x5c($sp)
/* 9FC6B0 80241EC0 8FB20058 */  lw        $s2, 0x58($sp)
/* 9FC6B4 80241EC4 8FB10054 */  lw        $s1, 0x54($sp)
/* 9FC6B8 80241EC8 8FB00050 */  lw        $s0, 0x50($sp)
/* 9FC6BC 80241ECC 0000102D */  daddu     $v0, $zero, $zero
/* 9FC6C0 80241ED0 03E00008 */  jr        $ra
/* 9FC6C4 80241ED4 27BD0070 */   addiu    $sp, $sp, 0x70
/* 9FC6C8 80241ED8 00000000 */  nop       
/* 9FC6CC 80241EDC 00000000 */  nop       
