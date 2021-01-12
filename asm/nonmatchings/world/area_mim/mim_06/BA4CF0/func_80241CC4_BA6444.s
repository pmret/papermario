.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CC4_BA6444
/* BA6444 80241CC4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BA6448 80241CC8 AFB20038 */  sw        $s2, 0x38($sp)
/* BA644C 80241CCC 0080902D */  daddu     $s2, $a0, $zero
/* BA6450 80241CD0 AFBF0048 */  sw        $ra, 0x48($sp)
/* BA6454 80241CD4 AFB50044 */  sw        $s5, 0x44($sp)
/* BA6458 80241CD8 AFB40040 */  sw        $s4, 0x40($sp)
/* BA645C 80241CDC AFB3003C */  sw        $s3, 0x3c($sp)
/* BA6460 80241CE0 AFB10034 */  sw        $s1, 0x34($sp)
/* BA6464 80241CE4 AFB00030 */  sw        $s0, 0x30($sp)
/* BA6468 80241CE8 8E510148 */  lw        $s1, 0x148($s2)
/* BA646C 80241CEC 86240008 */  lh        $a0, 8($s1)
/* BA6470 80241CF0 0C00EABB */  jal       get_npc_unsafe
/* BA6474 80241CF4 00A0802D */   daddu    $s0, $a1, $zero
/* BA6478 80241CF8 8E43000C */  lw        $v1, 0xc($s2)
/* BA647C 80241CFC 0240202D */  daddu     $a0, $s2, $zero
/* BA6480 80241D00 8C650000 */  lw        $a1, ($v1)
/* BA6484 80241D04 0C0B1EAF */  jal       get_variable
/* BA6488 80241D08 0040A82D */   daddu    $s5, $v0, $zero
/* BA648C 80241D0C AFA00010 */  sw        $zero, 0x10($sp)
/* BA6490 80241D10 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA6494 80241D14 8C630030 */  lw        $v1, 0x30($v1)
/* BA6498 80241D18 AFA30014 */  sw        $v1, 0x14($sp)
/* BA649C 80241D1C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA64A0 80241D20 8C63001C */  lw        $v1, 0x1c($v1)
/* BA64A4 80241D24 AFA30018 */  sw        $v1, 0x18($sp)
/* BA64A8 80241D28 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA64AC 80241D2C 8C630024 */  lw        $v1, 0x24($v1)
/* BA64B0 80241D30 AFA3001C */  sw        $v1, 0x1c($sp)
/* BA64B4 80241D34 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA64B8 80241D38 8C630028 */  lw        $v1, 0x28($v1)
/* BA64BC 80241D3C 27B40010 */  addiu     $s4, $sp, 0x10
/* BA64C0 80241D40 AFA30020 */  sw        $v1, 0x20($sp)
/* BA64C4 80241D44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA64C8 80241D48 3C014348 */  lui       $at, 0x4348
/* BA64CC 80241D4C 44810000 */  mtc1      $at, $f0
/* BA64D0 80241D50 8C63002C */  lw        $v1, 0x2c($v1)
/* BA64D4 80241D54 0040982D */  daddu     $s3, $v0, $zero
/* BA64D8 80241D58 E7A00028 */  swc1      $f0, 0x28($sp)
/* BA64DC 80241D5C A7A0002C */  sh        $zero, 0x2c($sp)
/* BA64E0 80241D60 16000005 */  bnez      $s0, .L80241D78
/* BA64E4 80241D64 AFA30024 */   sw       $v1, 0x24($sp)
/* BA64E8 80241D68 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA64EC 80241D6C 30420004 */  andi      $v0, $v0, 4
/* BA64F0 80241D70 10400011 */  beqz      $v0, .L80241DB8
/* BA64F4 80241D74 00000000 */   nop
.L80241D78:
/* BA64F8 80241D78 AE400070 */  sw        $zero, 0x70($s2)
/* BA64FC 80241D7C A6A0008E */  sh        $zero, 0x8e($s5)
/* BA6500 80241D80 8E2200CC */  lw        $v0, 0xcc($s1)
/* BA6504 80241D84 8C420000 */  lw        $v0, ($v0)
/* BA6508 80241D88 AEA20028 */  sw        $v0, 0x28($s5)
/* BA650C 80241D8C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA6510 80241D90 30420004 */  andi      $v0, $v0, 4
/* BA6514 80241D94 10400008 */  beqz      $v0, .L80241DB8
/* BA6518 80241D98 AE20006C */   sw       $zero, 0x6c($s1)
/* BA651C 80241D9C 24020063 */  addiu     $v0, $zero, 0x63
/* BA6520 80241DA0 AE420070 */  sw        $v0, 0x70($s2)
/* BA6524 80241DA4 AE400074 */  sw        $zero, 0x74($s2)
/* BA6528 80241DA8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA652C 80241DAC 2403FFFB */  addiu     $v1, $zero, -5
/* BA6530 80241DB0 00431024 */  and       $v0, $v0, $v1
/* BA6534 80241DB4 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241DB8:
/* BA6538 80241DB8 8E430070 */  lw        $v1, 0x70($s2)
/* BA653C 80241DBC 2410000B */  addiu     $s0, $zero, 0xb
/* BA6540 80241DC0 1070002A */  beq       $v1, $s0, .L80241E6C
/* BA6544 80241DC4 2862000C */   slti     $v0, $v1, 0xc
/* BA6548 80241DC8 1040000D */  beqz      $v0, .L80241E00
/* BA654C 80241DCC 24020001 */   addiu    $v0, $zero, 1
/* BA6550 80241DD0 1062001A */  beq       $v1, $v0, .L80241E3C
/* BA6554 80241DD4 28620002 */   slti     $v0, $v1, 2
/* BA6558 80241DD8 10400005 */  beqz      $v0, .L80241DF0
/* BA655C 80241DDC 2402000A */   addiu    $v0, $zero, 0xa
/* BA6560 80241DE0 10600013 */  beqz      $v1, .L80241E30
/* BA6564 80241DE4 0240202D */   daddu    $a0, $s2, $zero
/* BA6568 80241DE8 080907BB */  j         .L80241EEC
/* BA656C 80241DEC 00000000 */   nop
.L80241DF0:
/* BA6570 80241DF0 10620018 */  beq       $v1, $v0, .L80241E54
/* BA6574 80241DF4 0240202D */   daddu    $a0, $s2, $zero
/* BA6578 80241DF8 080907BB */  j         .L80241EEC
/* BA657C 80241DFC 00000000 */   nop
.L80241E00:
/* BA6580 80241E00 2402000D */  addiu     $v0, $zero, 0xd
/* BA6584 80241E04 10620029 */  beq       $v1, $v0, .L80241EAC
/* BA6588 80241E08 0062102A */   slt      $v0, $v1, $v0
/* BA658C 80241E0C 14400020 */  bnez      $v0, .L80241E90
/* BA6590 80241E10 0240202D */   daddu    $a0, $s2, $zero
/* BA6594 80241E14 2402000E */  addiu     $v0, $zero, 0xe
/* BA6598 80241E18 1062002D */  beq       $v1, $v0, .L80241ED0
/* BA659C 80241E1C 24020063 */   addiu    $v0, $zero, 0x63
/* BA65A0 80241E20 10620030 */  beq       $v1, $v0, .L80241EE4
/* BA65A4 80241E24 00000000 */   nop
/* BA65A8 80241E28 080907BB */  j         .L80241EEC
/* BA65AC 80241E2C 00000000 */   nop
.L80241E30:
/* BA65B0 80241E30 0260282D */  daddu     $a1, $s3, $zero
/* BA65B4 80241E34 0C090390 */  jal       func_80240E40_BA55C0
/* BA65B8 80241E38 0280302D */   daddu    $a2, $s4, $zero
.L80241E3C:
/* BA65BC 80241E3C 0240202D */  daddu     $a0, $s2, $zero
/* BA65C0 80241E40 0260282D */  daddu     $a1, $s3, $zero
/* BA65C4 80241E44 0C0903AB */  jal       func_80240EAC_BA562C
/* BA65C8 80241E48 0280302D */   daddu    $a2, $s4, $zero
/* BA65CC 80241E4C 080907BB */  j         .L80241EEC
/* BA65D0 80241E50 00000000 */   nop
.L80241E54:
/* BA65D4 80241E54 0260282D */  daddu     $a1, $s3, $zero
/* BA65D8 80241E58 0C0903EA */  jal       func_80240FA8_BA5728
/* BA65DC 80241E5C 0280302D */   daddu    $a2, $s4, $zero
/* BA65E0 80241E60 8E420070 */  lw        $v0, 0x70($s2)
/* BA65E4 80241E64 14500021 */  bne       $v0, $s0, .L80241EEC
/* BA65E8 80241E68 00000000 */   nop
.L80241E6C:
/* BA65EC 80241E6C 0240202D */  daddu     $a0, $s2, $zero
/* BA65F0 80241E70 0260282D */  daddu     $a1, $s3, $zero
/* BA65F4 80241E74 0C09067A */  jal       func_802419E8_BA6168
/* BA65F8 80241E78 0280302D */   daddu    $a2, $s4, $zero
/* BA65FC 80241E7C 8E430070 */  lw        $v1, 0x70($s2)
/* BA6600 80241E80 2402000C */  addiu     $v0, $zero, 0xc
/* BA6604 80241E84 14620019 */  bne       $v1, $v0, .L80241EEC
/* BA6608 80241E88 00000000 */   nop
/* BA660C 80241E8C 0240202D */  daddu     $a0, $s2, $zero
.L80241E90:
/* BA6610 80241E90 0260282D */  daddu     $a1, $s3, $zero
/* BA6614 80241E94 0C09069E */  jal       func_80241A78_BA61F8
/* BA6618 80241E98 0280302D */   daddu    $a2, $s4, $zero
/* BA661C 80241E9C 8E430070 */  lw        $v1, 0x70($s2)
/* BA6620 80241EA0 2402000D */  addiu     $v0, $zero, 0xd
/* BA6624 80241EA4 14620011 */  bne       $v1, $v0, .L80241EEC
/* BA6628 80241EA8 00000000 */   nop
.L80241EAC:
/* BA662C 80241EAC 0240202D */  daddu     $a0, $s2, $zero
/* BA6630 80241EB0 0260282D */  daddu     $a1, $s3, $zero
/* BA6634 80241EB4 0C0906DE */  jal       func_80241B78_BA62F8
/* BA6638 80241EB8 0280302D */   daddu    $a2, $s4, $zero
/* BA663C 80241EBC 8E430070 */  lw        $v1, 0x70($s2)
/* BA6640 80241EC0 2402000E */  addiu     $v0, $zero, 0xe
/* BA6644 80241EC4 14620009 */  bne       $v1, $v0, .L80241EEC
/* BA6648 80241EC8 00000000 */   nop
/* BA664C 80241ECC 0240202D */  daddu     $a0, $s2, $zero
.L80241ED0:
/* BA6650 80241ED0 0260282D */  daddu     $a1, $s3, $zero
/* BA6654 80241ED4 0C0906F6 */  jal       func_80241BD8_BA6358
/* BA6658 80241ED8 0280302D */   daddu    $a2, $s4, $zero
/* BA665C 80241EDC 080907BB */  j         .L80241EEC
/* BA6660 80241EE0 00000000 */   nop
.L80241EE4:
/* BA6664 80241EE4 0C0129CF */  jal       func_8004A73C
/* BA6668 80241EE8 0240202D */   daddu    $a0, $s2, $zero
.L80241EEC:
/* BA666C 80241EEC 8FBF0048 */  lw        $ra, 0x48($sp)
/* BA6670 80241EF0 8FB50044 */  lw        $s5, 0x44($sp)
/* BA6674 80241EF4 8FB40040 */  lw        $s4, 0x40($sp)
/* BA6678 80241EF8 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA667C 80241EFC 8FB20038 */  lw        $s2, 0x38($sp)
/* BA6680 80241F00 8FB10034 */  lw        $s1, 0x34($sp)
/* BA6684 80241F04 8FB00030 */  lw        $s0, 0x30($sp)
/* BA6688 80241F08 0000102D */  daddu     $v0, $zero, $zero
/* BA668C 80241F0C 03E00008 */  jr        $ra
/* BA6690 80241F10 27BD0050 */   addiu    $sp, $sp, 0x50
