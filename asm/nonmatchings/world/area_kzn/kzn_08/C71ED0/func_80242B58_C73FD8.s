.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B58_C73FD8
/* C73FD8 80242B58 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C73FDC 80242B5C AFB20038 */  sw        $s2, 0x38($sp)
/* C73FE0 80242B60 0080902D */  daddu     $s2, $a0, $zero
/* C73FE4 80242B64 AFBF0048 */  sw        $ra, 0x48($sp)
/* C73FE8 80242B68 AFB50044 */  sw        $s5, 0x44($sp)
/* C73FEC 80242B6C AFB40040 */  sw        $s4, 0x40($sp)
/* C73FF0 80242B70 AFB3003C */  sw        $s3, 0x3c($sp)
/* C73FF4 80242B74 AFB10034 */  sw        $s1, 0x34($sp)
/* C73FF8 80242B78 AFB00030 */  sw        $s0, 0x30($sp)
/* C73FFC 80242B7C 8E510148 */  lw        $s1, 0x148($s2)
/* C74000 80242B80 86240008 */  lh        $a0, 8($s1)
/* C74004 80242B84 0C00EABB */  jal       get_npc_unsafe
/* C74008 80242B88 00A0802D */   daddu    $s0, $a1, $zero
/* C7400C 80242B8C 8E43000C */  lw        $v1, 0xc($s2)
/* C74010 80242B90 0240202D */  daddu     $a0, $s2, $zero
/* C74014 80242B94 8C650000 */  lw        $a1, ($v1)
/* C74018 80242B98 0C0B1EAF */  jal       get_variable
/* C7401C 80242B9C 0040A82D */   daddu    $s5, $v0, $zero
/* C74020 80242BA0 AFA00010 */  sw        $zero, 0x10($sp)
/* C74024 80242BA4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C74028 80242BA8 8C630030 */  lw        $v1, 0x30($v1)
/* C7402C 80242BAC AFA30014 */  sw        $v1, 0x14($sp)
/* C74030 80242BB0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C74034 80242BB4 8C63001C */  lw        $v1, 0x1c($v1)
/* C74038 80242BB8 AFA30018 */  sw        $v1, 0x18($sp)
/* C7403C 80242BBC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C74040 80242BC0 8C630024 */  lw        $v1, 0x24($v1)
/* C74044 80242BC4 AFA3001C */  sw        $v1, 0x1c($sp)
/* C74048 80242BC8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C7404C 80242BCC 8C630028 */  lw        $v1, 0x28($v1)
/* C74050 80242BD0 27B40010 */  addiu     $s4, $sp, 0x10
/* C74054 80242BD4 AFA30020 */  sw        $v1, 0x20($sp)
/* C74058 80242BD8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C7405C 80242BDC 3C014282 */  lui       $at, 0x4282
/* C74060 80242BE0 44810000 */  mtc1      $at, $f0
/* C74064 80242BE4 8C63002C */  lw        $v1, 0x2c($v1)
/* C74068 80242BE8 0040982D */  daddu     $s3, $v0, $zero
/* C7406C 80242BEC E7A00028 */  swc1      $f0, 0x28($sp)
/* C74070 80242BF0 A7A0002C */  sh        $zero, 0x2c($sp)
/* C74074 80242BF4 16000005 */  bnez      $s0, .L80242C0C
/* C74078 80242BF8 AFA30024 */   sw       $v1, 0x24($sp)
/* C7407C 80242BFC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C74080 80242C00 30420004 */  andi      $v0, $v0, 4
/* C74084 80242C04 10400020 */  beqz      $v0, .L80242C88
/* C74088 80242C08 00000000 */   nop
.L80242C0C:
/* C7408C 80242C0C 2404F7FF */  addiu     $a0, $zero, -0x801
/* C74090 80242C10 AE400070 */  sw        $zero, 0x70($s2)
/* C74094 80242C14 A6A0008E */  sh        $zero, 0x8e($s5)
/* C74098 80242C18 8E2200CC */  lw        $v0, 0xcc($s1)
/* C7409C 80242C1C 8EA30000 */  lw        $v1, ($s5)
/* C740A0 80242C20 8C420000 */  lw        $v0, ($v0)
/* C740A4 80242C24 00641824 */  and       $v1, $v1, $a0
/* C740A8 80242C28 AEA30000 */  sw        $v1, ($s5)
/* C740AC 80242C2C AEA20028 */  sw        $v0, 0x28($s5)
/* C740B0 80242C30 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C740B4 80242C34 8C420034 */  lw        $v0, 0x34($v0)
/* C740B8 80242C38 54400005 */  bnel      $v0, $zero, .L80242C50
/* C740BC 80242C3C 2402FDFF */   addiu    $v0, $zero, -0x201
/* C740C0 80242C40 34620200 */  ori       $v0, $v1, 0x200
/* C740C4 80242C44 2403FFF7 */  addiu     $v1, $zero, -9
/* C740C8 80242C48 08090B16 */  j         .L80242C58
/* C740CC 80242C4C 00431024 */   and      $v0, $v0, $v1
.L80242C50:
/* C740D0 80242C50 00621024 */  and       $v0, $v1, $v0
/* C740D4 80242C54 34420008 */  ori       $v0, $v0, 8
.L80242C58:
/* C740D8 80242C58 AEA20000 */  sw        $v0, ($s5)
/* C740DC 80242C5C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C740E0 80242C60 30420004 */  andi      $v0, $v0, 4
/* C740E4 80242C64 10400007 */  beqz      $v0, .L80242C84
/* C740E8 80242C68 24020063 */   addiu    $v0, $zero, 0x63
/* C740EC 80242C6C AE420070 */  sw        $v0, 0x70($s2)
/* C740F0 80242C70 AE400074 */  sw        $zero, 0x74($s2)
/* C740F4 80242C74 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C740F8 80242C78 2403FFFB */  addiu     $v1, $zero, -5
/* C740FC 80242C7C 00431024 */  and       $v0, $v0, $v1
/* C74100 80242C80 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80242C84:
/* C74104 80242C84 AE20006C */  sw        $zero, 0x6c($s1)
.L80242C88:
/* C74108 80242C88 8E420070 */  lw        $v0, 0x70($s2)
/* C7410C 80242C8C 2842001E */  slti      $v0, $v0, 0x1e
/* C74110 80242C90 10400009 */  beqz      $v0, .L80242CB8
/* C74114 80242C94 00000000 */   nop
/* C74118 80242C98 8E22006C */  lw        $v0, 0x6c($s1)
/* C7411C 80242C9C 14400006 */  bnez      $v0, .L80242CB8
/* C74120 80242CA0 00000000 */   nop
/* C74124 80242CA4 0C0909D1 */  jal       func_80242744_C73BC4
/* C74128 80242CA8 0240202D */   daddu    $a0, $s2, $zero
/* C7412C 80242CAC 10400002 */  beqz      $v0, .L80242CB8
/* C74130 80242CB0 2402001E */   addiu    $v0, $zero, 0x1e
/* C74134 80242CB4 AE420070 */  sw        $v0, 0x70($s2)
.L80242CB8:
/* C74138 80242CB8 8E430070 */  lw        $v1, 0x70($s2)
/* C7413C 80242CBC 2C620064 */  sltiu     $v0, $v1, 0x64
/* C74140 80242CC0 10400048 */  beqz      $v0, .L80242DE4
/* C74144 80242CC4 00031080 */   sll      $v0, $v1, 2
/* C74148 80242CC8 3C018024 */  lui       $at, %hi(D_802456A0)
/* C7414C 80242CCC 00220821 */  addu      $at, $at, $v0
/* C74150 80242CD0 8C2256A0 */  lw        $v0, %lo(D_802456A0)($at)
/* C74154 80242CD4 00400008 */  jr        $v0
/* C74158 80242CD8 00000000 */   nop
/* C7415C 80242CDC 0240202D */  daddu     $a0, $s2, $zero
/* C74160 80242CE0 0260282D */  daddu     $a1, $s3, $zero
/* C74164 80242CE4 0C012568 */  jal       func_800495A0
/* C74168 80242CE8 0280302D */   daddu    $a2, $s4, $zero
/* C7416C 80242CEC 0240202D */  daddu     $a0, $s2, $zero
/* C74170 80242CF0 0260282D */  daddu     $a1, $s3, $zero
/* C74174 80242CF4 0C0125AE */  jal       func_800496B8
/* C74178 80242CF8 0280302D */   daddu    $a2, $s4, $zero
/* C7417C 80242CFC 08090B79 */  j         .L80242DE4
/* C74180 80242D00 00000000 */   nop
/* C74184 80242D04 0240202D */  daddu     $a0, $s2, $zero
/* C74188 80242D08 0260282D */  daddu     $a1, $s3, $zero
/* C7418C 80242D0C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* C74190 80242D10 0280302D */   daddu    $a2, $s4, $zero
/* C74194 80242D14 0240202D */  daddu     $a0, $s2, $zero
/* C74198 80242D18 0260282D */  daddu     $a1, $s3, $zero
/* C7419C 80242D1C 0C012701 */  jal       func_80049C04
/* C741A0 80242D20 0280302D */   daddu    $a2, $s4, $zero
/* C741A4 80242D24 08090B79 */  j         .L80242DE4
/* C741A8 80242D28 00000000 */   nop
/* C741AC 80242D2C 0240202D */  daddu     $a0, $s2, $zero
/* C741B0 80242D30 0260282D */  daddu     $a1, $s3, $zero
/* C741B4 80242D34 0C01278F */  jal       func_80049E3C
/* C741B8 80242D38 0280302D */   daddu    $a2, $s4, $zero
/* C741BC 80242D3C 0240202D */  daddu     $a0, $s2, $zero
/* C741C0 80242D40 0260282D */  daddu     $a1, $s3, $zero
/* C741C4 80242D44 0C0127B3 */  jal       func_80049ECC
/* C741C8 80242D48 0280302D */   daddu    $a2, $s4, $zero
/* C741CC 80242D4C 08090B79 */  j         .L80242DE4
/* C741D0 80242D50 00000000 */   nop
/* C741D4 80242D54 0240202D */  daddu     $a0, $s2, $zero
/* C741D8 80242D58 0260282D */  daddu     $a1, $s3, $zero
/* C741DC 80242D5C 0C0127DF */  jal       func_80049F7C
/* C741E0 80242D60 0280302D */   daddu    $a2, $s4, $zero
/* C741E4 80242D64 0240202D */  daddu     $a0, $s2, $zero
/* C741E8 80242D68 0260282D */  daddu     $a1, $s3, $zero
/* C741EC 80242D6C 0C012849 */  jal       func_8004A124
/* C741F0 80242D70 0280302D */   daddu    $a2, $s4, $zero
/* C741F4 80242D74 08090B79 */  j         .L80242DE4
/* C741F8 80242D78 00000000 */   nop
/* C741FC 80242D7C 0240202D */  daddu     $a0, $s2, $zero
/* C74200 80242D80 0260282D */  daddu     $a1, $s3, $zero
/* C74204 80242D84 0C0128FA */  jal       func_8004A3E8
/* C74208 80242D88 0280302D */   daddu    $a2, $s4, $zero
/* C7420C 80242D8C 08090B79 */  j         .L80242DE4
/* C74210 80242D90 00000000 */   nop
/* C74214 80242D94 0C09094F */  jal       kzn_08_UnkNpcAIFunc6
/* C74218 80242D98 0240202D */   daddu    $a0, $s2, $zero
/* C7421C 80242D9C 0C09096A */  jal       kzn_08_UnkNpcAIFunc7
/* C74220 80242DA0 0240202D */   daddu    $a0, $s2, $zero
/* C74224 80242DA4 8E430070 */  lw        $v1, 0x70($s2)
/* C74228 80242DA8 24020020 */  addiu     $v0, $zero, 0x20
/* C7422C 80242DAC 1462000D */  bne       $v1, $v0, .L80242DE4
/* C74230 80242DB0 00000000 */   nop
/* C74234 80242DB4 0C090986 */  jal       kzn_08_UnkNpcAIFunc8
/* C74238 80242DB8 0240202D */   daddu    $a0, $s2, $zero
/* C7423C 80242DBC 8E430070 */  lw        $v1, 0x70($s2)
/* C74240 80242DC0 24020021 */  addiu     $v0, $zero, 0x21
/* C74244 80242DC4 14620007 */  bne       $v1, $v0, .L80242DE4
/* C74248 80242DC8 00000000 */   nop
/* C7424C 80242DCC 0C0909BC */  jal       kzn_08_UnkNpcAIFunc5
/* C74250 80242DD0 0240202D */   daddu    $a0, $s2, $zero
/* C74254 80242DD4 08090B79 */  j         .L80242DE4
/* C74258 80242DD8 00000000 */   nop
/* C7425C 80242DDC 0C0129CF */  jal       func_8004A73C
/* C74260 80242DE0 0240202D */   daddu    $a0, $s2, $zero
.L80242DE4:
/* C74264 80242DE4 8FBF0048 */  lw        $ra, 0x48($sp)
/* C74268 80242DE8 8FB50044 */  lw        $s5, 0x44($sp)
/* C7426C 80242DEC 8FB40040 */  lw        $s4, 0x40($sp)
/* C74270 80242DF0 8FB3003C */  lw        $s3, 0x3c($sp)
/* C74274 80242DF4 8FB20038 */  lw        $s2, 0x38($sp)
/* C74278 80242DF8 8FB10034 */  lw        $s1, 0x34($sp)
/* C7427C 80242DFC 8FB00030 */  lw        $s0, 0x30($sp)
/* C74280 80242E00 0000102D */  daddu     $v0, $zero, $zero
/* C74284 80242E04 03E00008 */  jr        $ra
/* C74288 80242E08 27BD0050 */   addiu    $sp, $sp, 0x50
