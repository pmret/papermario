.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C84
/* B5FF34 80241C84 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B5FF38 80241C88 AFB20038 */  sw        $s2, 0x38($sp)
/* B5FF3C 80241C8C 0080902D */  daddu     $s2, $a0, $zero
/* B5FF40 80241C90 AFBF0048 */  sw        $ra, 0x48($sp)
/* B5FF44 80241C94 AFB50044 */  sw        $s5, 0x44($sp)
/* B5FF48 80241C98 AFB40040 */  sw        $s4, 0x40($sp)
/* B5FF4C 80241C9C AFB3003C */  sw        $s3, 0x3c($sp)
/* B5FF50 80241CA0 AFB10034 */  sw        $s1, 0x34($sp)
/* B5FF54 80241CA4 AFB00030 */  sw        $s0, 0x30($sp)
/* B5FF58 80241CA8 8E510148 */  lw        $s1, 0x148($s2)
/* B5FF5C 80241CAC 86240008 */  lh        $a0, 8($s1)
/* B5FF60 80241CB0 0C00EABB */  jal       get_npc_unsafe
/* B5FF64 80241CB4 00A0802D */   daddu    $s0, $a1, $zero
/* B5FF68 80241CB8 8E43000C */  lw        $v1, 0xc($s2)
/* B5FF6C 80241CBC 0240202D */  daddu     $a0, $s2, $zero
/* B5FF70 80241CC0 8C650000 */  lw        $a1, ($v1)
/* B5FF74 80241CC4 0C0B1EAF */  jal       get_variable
/* B5FF78 80241CC8 0040A82D */   daddu    $s5, $v0, $zero
/* B5FF7C 80241CCC AFA00010 */  sw        $zero, 0x10($sp)
/* B5FF80 80241CD0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5FF84 80241CD4 8C630030 */  lw        $v1, 0x30($v1)
/* B5FF88 80241CD8 AFA30014 */  sw        $v1, 0x14($sp)
/* B5FF8C 80241CDC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5FF90 80241CE0 8C63001C */  lw        $v1, 0x1c($v1)
/* B5FF94 80241CE4 AFA30018 */  sw        $v1, 0x18($sp)
/* B5FF98 80241CE8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5FF9C 80241CEC 8C630024 */  lw        $v1, 0x24($v1)
/* B5FFA0 80241CF0 AFA3001C */  sw        $v1, 0x1c($sp)
/* B5FFA4 80241CF4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5FFA8 80241CF8 8C630028 */  lw        $v1, 0x28($v1)
/* B5FFAC 80241CFC 27B40010 */  addiu     $s4, $sp, 0x10
/* B5FFB0 80241D00 AFA30020 */  sw        $v1, 0x20($sp)
/* B5FFB4 80241D04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5FFB8 80241D08 3C014282 */  lui       $at, 0x4282
/* B5FFBC 80241D0C 44810000 */  mtc1      $at, $f0
/* B5FFC0 80241D10 8C63002C */  lw        $v1, 0x2c($v1)
/* B5FFC4 80241D14 0040982D */  daddu     $s3, $v0, $zero
/* B5FFC8 80241D18 E7A00028 */  swc1      $f0, 0x28($sp)
/* B5FFCC 80241D1C A7A0002C */  sh        $zero, 0x2c($sp)
/* B5FFD0 80241D20 16000005 */  bnez      $s0, .L80241D38
/* B5FFD4 80241D24 AFA30024 */   sw       $v1, 0x24($sp)
/* B5FFD8 80241D28 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5FFDC 80241D2C 30420004 */  andi      $v0, $v0, 4
/* B5FFE0 80241D30 10400020 */  beqz      $v0, .L80241DB4
/* B5FFE4 80241D34 00000000 */   nop      
.L80241D38:
/* B5FFE8 80241D38 2404F7FF */  addiu     $a0, $zero, -0x801
/* B5FFEC 80241D3C AE400070 */  sw        $zero, 0x70($s2)
/* B5FFF0 80241D40 A6A0008E */  sh        $zero, 0x8e($s5)
/* B5FFF4 80241D44 8E2200CC */  lw        $v0, 0xcc($s1)
/* B5FFF8 80241D48 8EA30000 */  lw        $v1, ($s5)
/* B5FFFC 80241D4C 8C420000 */  lw        $v0, ($v0)
/* B60000 80241D50 00641824 */  and       $v1, $v1, $a0
/* B60004 80241D54 AEA30000 */  sw        $v1, ($s5)
/* B60008 80241D58 AEA20028 */  sw        $v0, 0x28($s5)
/* B6000C 80241D5C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B60010 80241D60 8C420034 */  lw        $v0, 0x34($v0)
/* B60014 80241D64 54400005 */  bnel      $v0, $zero, .L80241D7C
/* B60018 80241D68 2402FDFF */   addiu    $v0, $zero, -0x201
/* B6001C 80241D6C 34620200 */  ori       $v0, $v1, 0x200
/* B60020 80241D70 2403FFF7 */  addiu     $v1, $zero, -9
/* B60024 80241D74 08090761 */  j         .L80241D84
/* B60028 80241D78 00431024 */   and      $v0, $v0, $v1
.L80241D7C:
/* B6002C 80241D7C 00621024 */  and       $v0, $v1, $v0
/* B60030 80241D80 34420008 */  ori       $v0, $v0, 8
.L80241D84:
/* B60034 80241D84 AEA20000 */  sw        $v0, ($s5)
/* B60038 80241D88 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B6003C 80241D8C 30420004 */  andi      $v0, $v0, 4
/* B60040 80241D90 10400007 */  beqz      $v0, .L80241DB0
/* B60044 80241D94 24020063 */   addiu    $v0, $zero, 0x63
/* B60048 80241D98 AE420070 */  sw        $v0, 0x70($s2)
/* B6004C 80241D9C AE400074 */  sw        $zero, 0x74($s2)
/* B60050 80241DA0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B60054 80241DA4 2403FFFB */  addiu     $v1, $zero, -5
/* B60058 80241DA8 00431024 */  and       $v0, $v0, $v1
/* B6005C 80241DAC AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241DB0:
/* B60060 80241DB0 AE20006C */  sw        $zero, 0x6c($s1)
.L80241DB4:
/* B60064 80241DB4 8E420070 */  lw        $v0, 0x70($s2)
/* B60068 80241DB8 2842001E */  slti      $v0, $v0, 0x1e
/* B6006C 80241DBC 10400009 */  beqz      $v0, .L80241DE4
/* B60070 80241DC0 00000000 */   nop      
/* B60074 80241DC4 8E22006C */  lw        $v0, 0x6c($s1)
/* B60078 80241DC8 14400006 */  bnez      $v0, .L80241DE4
/* B6007C 80241DCC 00000000 */   nop      
/* B60080 80241DD0 0C09061C */  jal       func_80241870
/* B60084 80241DD4 0240202D */   daddu    $a0, $s2, $zero
/* B60088 80241DD8 10400002 */  beqz      $v0, .L80241DE4
/* B6008C 80241DDC 2402001E */   addiu    $v0, $zero, 0x1e
/* B60090 80241DE0 AE420070 */  sw        $v0, 0x70($s2)
.L80241DE4:
/* B60094 80241DE4 8E430070 */  lw        $v1, 0x70($s2)
/* B60098 80241DE8 2C620064 */  sltiu     $v0, $v1, 0x64
/* B6009C 80241DEC 10400048 */  beqz      $v0, .L80241F10
/* B600A0 80241DF0 00031080 */   sll      $v0, $v1, 2
/* B600A4 80241DF4 3C018024 */  lui       $at, 0x8024
/* B600A8 80241DF8 00220821 */  addu      $at, $at, $v0
/* B600AC 80241DFC 8C2274E0 */  lw        $v0, 0x74e0($at)
/* B600B0 80241E00 00400008 */  jr        $v0
/* B600B4 80241E04 00000000 */   nop      
/* B600B8 80241E08 0240202D */  daddu     $a0, $s2, $zero
/* B600BC 80241E0C 0260282D */  daddu     $a1, $s3, $zero
/* B600C0 80241E10 0C012568 */  jal       func_800495A0
/* B600C4 80241E14 0280302D */   daddu    $a2, $s4, $zero
/* B600C8 80241E18 0240202D */  daddu     $a0, $s2, $zero
/* B600CC 80241E1C 0260282D */  daddu     $a1, $s3, $zero
/* B600D0 80241E20 0C0125AE */  jal       func_800496B8
/* B600D4 80241E24 0280302D */   daddu    $a2, $s4, $zero
/* B600D8 80241E28 080907C4 */  j         .L80241F10
/* B600DC 80241E2C 00000000 */   nop      
/* B600E0 80241E30 0240202D */  daddu     $a0, $s2, $zero
/* B600E4 80241E34 0260282D */  daddu     $a1, $s3, $zero
/* B600E8 80241E38 0C0126D1 */  jal       func_80049B44
/* B600EC 80241E3C 0280302D */   daddu    $a2, $s4, $zero
/* B600F0 80241E40 0240202D */  daddu     $a0, $s2, $zero
/* B600F4 80241E44 0260282D */  daddu     $a1, $s3, $zero
/* B600F8 80241E48 0C012701 */  jal       func_80049C04
/* B600FC 80241E4C 0280302D */   daddu    $a2, $s4, $zero
/* B60100 80241E50 080907C4 */  j         .L80241F10
/* B60104 80241E54 00000000 */   nop      
/* B60108 80241E58 0240202D */  daddu     $a0, $s2, $zero
/* B6010C 80241E5C 0260282D */  daddu     $a1, $s3, $zero
/* B60110 80241E60 0C01278F */  jal       func_80049E3C
/* B60114 80241E64 0280302D */   daddu    $a2, $s4, $zero
/* B60118 80241E68 0240202D */  daddu     $a0, $s2, $zero
/* B6011C 80241E6C 0260282D */  daddu     $a1, $s3, $zero
/* B60120 80241E70 0C0127B3 */  jal       func_80049ECC
/* B60124 80241E74 0280302D */   daddu    $a2, $s4, $zero
/* B60128 80241E78 080907C4 */  j         .L80241F10
/* B6012C 80241E7C 00000000 */   nop      
/* B60130 80241E80 0240202D */  daddu     $a0, $s2, $zero
/* B60134 80241E84 0260282D */  daddu     $a1, $s3, $zero
/* B60138 80241E88 0C0127DF */  jal       func_80049F7C
/* B6013C 80241E8C 0280302D */   daddu    $a2, $s4, $zero
/* B60140 80241E90 0240202D */  daddu     $a0, $s2, $zero
/* B60144 80241E94 0260282D */  daddu     $a1, $s3, $zero
/* B60148 80241E98 0C012849 */  jal       func_8004A124
/* B6014C 80241E9C 0280302D */   daddu    $a2, $s4, $zero
/* B60150 80241EA0 080907C4 */  j         .L80241F10
/* B60154 80241EA4 00000000 */   nop      
/* B60158 80241EA8 0240202D */  daddu     $a0, $s2, $zero
/* B6015C 80241EAC 0260282D */  daddu     $a1, $s3, $zero
/* B60160 80241EB0 0C0128FA */  jal       func_8004A3E8
/* B60164 80241EB4 0280302D */   daddu    $a2, $s4, $zero
/* B60168 80241EB8 080907C4 */  j         .L80241F10
/* B6016C 80241EBC 00000000 */   nop      
/* B60170 80241EC0 0C09059A */  jal       func_80241668
/* B60174 80241EC4 0240202D */   daddu    $a0, $s2, $zero
/* B60178 80241EC8 0C0905B5 */  jal       func_802416D4_B5F984
/* B6017C 80241ECC 0240202D */   daddu    $a0, $s2, $zero
/* B60180 80241ED0 8E430070 */  lw        $v1, 0x70($s2)
/* B60184 80241ED4 24020020 */  addiu     $v0, $zero, 0x20
/* B60188 80241ED8 1462000D */  bne       $v1, $v0, .L80241F10
/* B6018C 80241EDC 00000000 */   nop      
/* B60190 80241EE0 0C0905D1 */  jal       func_80241744
/* B60194 80241EE4 0240202D */   daddu    $a0, $s2, $zero
/* B60198 80241EE8 8E430070 */  lw        $v1, 0x70($s2)
/* B6019C 80241EEC 24020021 */  addiu     $v0, $zero, 0x21
/* B601A0 80241EF0 14620007 */  bne       $v1, $v0, .L80241F10
/* B601A4 80241EF4 00000000 */   nop      
/* B601A8 80241EF8 0C090607 */  jal       func_8024181C
/* B601AC 80241EFC 0240202D */   daddu    $a0, $s2, $zero
/* B601B0 80241F00 080907C4 */  j         .L80241F10
/* B601B4 80241F04 00000000 */   nop      
/* B601B8 80241F08 0C0129CF */  jal       func_8004A73C
/* B601BC 80241F0C 0240202D */   daddu    $a0, $s2, $zero
.L80241F10:
/* B601C0 80241F10 8FBF0048 */  lw        $ra, 0x48($sp)
/* B601C4 80241F14 8FB50044 */  lw        $s5, 0x44($sp)
/* B601C8 80241F18 8FB40040 */  lw        $s4, 0x40($sp)
/* B601CC 80241F1C 8FB3003C */  lw        $s3, 0x3c($sp)
/* B601D0 80241F20 8FB20038 */  lw        $s2, 0x38($sp)
/* B601D4 80241F24 8FB10034 */  lw        $s1, 0x34($sp)
/* B601D8 80241F28 8FB00030 */  lw        $s0, 0x30($sp)
/* B601DC 80241F2C 0000102D */  daddu     $v0, $zero, $zero
/* B601E0 80241F30 03E00008 */  jr        $ra
/* B601E4 80241F34 27BD0050 */   addiu    $sp, $sp, 0x50
