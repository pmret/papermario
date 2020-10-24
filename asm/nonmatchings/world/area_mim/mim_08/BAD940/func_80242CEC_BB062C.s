.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CEC_BB062C
/* BB062C 80242CEC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BB0630 80242CF0 AFB20038 */  sw        $s2, 0x38($sp)
/* BB0634 80242CF4 0080902D */  daddu     $s2, $a0, $zero
/* BB0638 80242CF8 AFBF0048 */  sw        $ra, 0x48($sp)
/* BB063C 80242CFC AFB50044 */  sw        $s5, 0x44($sp)
/* BB0640 80242D00 AFB40040 */  sw        $s4, 0x40($sp)
/* BB0644 80242D04 AFB3003C */  sw        $s3, 0x3c($sp)
/* BB0648 80242D08 AFB10034 */  sw        $s1, 0x34($sp)
/* BB064C 80242D0C AFB00030 */  sw        $s0, 0x30($sp)
/* BB0650 80242D10 8E510148 */  lw        $s1, 0x148($s2)
/* BB0654 80242D14 86240008 */  lh        $a0, 8($s1)
/* BB0658 80242D18 0C00EABB */  jal       get_npc_unsafe
/* BB065C 80242D1C 00A0802D */   daddu    $s0, $a1, $zero
/* BB0660 80242D20 8E43000C */  lw        $v1, 0xc($s2)
/* BB0664 80242D24 0240202D */  daddu     $a0, $s2, $zero
/* BB0668 80242D28 8C650000 */  lw        $a1, ($v1)
/* BB066C 80242D2C 0C0B1EAF */  jal       get_variable
/* BB0670 80242D30 0040A82D */   daddu    $s5, $v0, $zero
/* BB0674 80242D34 AFA00010 */  sw        $zero, 0x10($sp)
/* BB0678 80242D38 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BB067C 80242D3C 8C630030 */  lw        $v1, 0x30($v1)
/* BB0680 80242D40 AFA30014 */  sw        $v1, 0x14($sp)
/* BB0684 80242D44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BB0688 80242D48 8C63001C */  lw        $v1, 0x1c($v1)
/* BB068C 80242D4C AFA30018 */  sw        $v1, 0x18($sp)
/* BB0690 80242D50 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BB0694 80242D54 8C630024 */  lw        $v1, 0x24($v1)
/* BB0698 80242D58 AFA3001C */  sw        $v1, 0x1c($sp)
/* BB069C 80242D5C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BB06A0 80242D60 8C630028 */  lw        $v1, 0x28($v1)
/* BB06A4 80242D64 27B40010 */  addiu     $s4, $sp, 0x10
/* BB06A8 80242D68 AFA30020 */  sw        $v1, 0x20($sp)
/* BB06AC 80242D6C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BB06B0 80242D70 3C014348 */  lui       $at, 0x4348
/* BB06B4 80242D74 44810000 */  mtc1      $at, $f0
/* BB06B8 80242D78 8C63002C */  lw        $v1, 0x2c($v1)
/* BB06BC 80242D7C 0040982D */  daddu     $s3, $v0, $zero
/* BB06C0 80242D80 E7A00028 */  swc1      $f0, 0x28($sp)
/* BB06C4 80242D84 A7A0002C */  sh        $zero, 0x2c($sp)
/* BB06C8 80242D88 16000005 */  bnez      $s0, .L80242DA0
/* BB06CC 80242D8C AFA30024 */   sw       $v1, 0x24($sp)
/* BB06D0 80242D90 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BB06D4 80242D94 30420004 */  andi      $v0, $v0, 4
/* BB06D8 80242D98 10400011 */  beqz      $v0, .L80242DE0
/* BB06DC 80242D9C 00000000 */   nop      
.L80242DA0:
/* BB06E0 80242DA0 AE400070 */  sw        $zero, 0x70($s2)
/* BB06E4 80242DA4 A6A0008E */  sh        $zero, 0x8e($s5)
/* BB06E8 80242DA8 8E2200CC */  lw        $v0, 0xcc($s1)
/* BB06EC 80242DAC 8C420000 */  lw        $v0, ($v0)
/* BB06F0 80242DB0 AEA20028 */  sw        $v0, 0x28($s5)
/* BB06F4 80242DB4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BB06F8 80242DB8 30420004 */  andi      $v0, $v0, 4
/* BB06FC 80242DBC 10400008 */  beqz      $v0, .L80242DE0
/* BB0700 80242DC0 AE20006C */   sw       $zero, 0x6c($s1)
/* BB0704 80242DC4 24020063 */  addiu     $v0, $zero, 0x63
/* BB0708 80242DC8 AE420070 */  sw        $v0, 0x70($s2)
/* BB070C 80242DCC AE400074 */  sw        $zero, 0x74($s2)
/* BB0710 80242DD0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BB0714 80242DD4 2403FFFB */  addiu     $v1, $zero, -5
/* BB0718 80242DD8 00431024 */  and       $v0, $v0, $v1
/* BB071C 80242DDC AE2200B0 */  sw        $v0, 0xb0($s1)
.L80242DE0:
/* BB0720 80242DE0 8E430070 */  lw        $v1, 0x70($s2)
/* BB0724 80242DE4 2410000B */  addiu     $s0, $zero, 0xb
/* BB0728 80242DE8 1070002A */  beq       $v1, $s0, .L80242E94
/* BB072C 80242DEC 2862000C */   slti     $v0, $v1, 0xc
/* BB0730 80242DF0 1040000D */  beqz      $v0, .L80242E28
/* BB0734 80242DF4 24020001 */   addiu    $v0, $zero, 1
/* BB0738 80242DF8 1062001A */  beq       $v1, $v0, .L80242E64
/* BB073C 80242DFC 28620002 */   slti     $v0, $v1, 2
/* BB0740 80242E00 10400005 */  beqz      $v0, .L80242E18
/* BB0744 80242E04 2402000A */   addiu    $v0, $zero, 0xa
/* BB0748 80242E08 10600013 */  beqz      $v1, .L80242E58
/* BB074C 80242E0C 0240202D */   daddu    $a0, $s2, $zero
/* BB0750 80242E10 08090BC5 */  j         .L80242F14
/* BB0754 80242E14 00000000 */   nop      
.L80242E18:
/* BB0758 80242E18 10620018 */  beq       $v1, $v0, .L80242E7C
/* BB075C 80242E1C 0240202D */   daddu    $a0, $s2, $zero
/* BB0760 80242E20 08090BC5 */  j         .L80242F14
/* BB0764 80242E24 00000000 */   nop      
.L80242E28:
/* BB0768 80242E28 2402000D */  addiu     $v0, $zero, 0xd
/* BB076C 80242E2C 10620029 */  beq       $v1, $v0, .L80242ED4
/* BB0770 80242E30 0062102A */   slt      $v0, $v1, $v0
/* BB0774 80242E34 14400020 */  bnez      $v0, .L80242EB8
/* BB0778 80242E38 0240202D */   daddu    $a0, $s2, $zero
/* BB077C 80242E3C 2402000E */  addiu     $v0, $zero, 0xe
/* BB0780 80242E40 1062002D */  beq       $v1, $v0, .L80242EF8
/* BB0784 80242E44 24020063 */   addiu    $v0, $zero, 0x63
/* BB0788 80242E48 10620030 */  beq       $v1, $v0, .L80242F0C
/* BB078C 80242E4C 00000000 */   nop      
/* BB0790 80242E50 08090BC5 */  j         .L80242F14
/* BB0794 80242E54 00000000 */   nop      
.L80242E58:
/* BB0798 80242E58 0260282D */  daddu     $a1, $s3, $zero
/* BB079C 80242E5C 0C09079A */  jal       func_80241E68_BAF7A8
/* BB07A0 80242E60 0280302D */   daddu    $a2, $s4, $zero
.L80242E64:
/* BB07A4 80242E64 0240202D */  daddu     $a0, $s2, $zero
/* BB07A8 80242E68 0260282D */  daddu     $a1, $s3, $zero
/* BB07AC 80242E6C 0C0907B5 */  jal       func_80241ED4_BAF814
/* BB07B0 80242E70 0280302D */   daddu    $a2, $s4, $zero
/* BB07B4 80242E74 08090BC5 */  j         .L80242F14
/* BB07B8 80242E78 00000000 */   nop      
.L80242E7C:
/* BB07BC 80242E7C 0260282D */  daddu     $a1, $s3, $zero
/* BB07C0 80242E80 0C0907F4 */  jal       func_80241FD0_BAF910
/* BB07C4 80242E84 0280302D */   daddu    $a2, $s4, $zero
/* BB07C8 80242E88 8E420070 */  lw        $v0, 0x70($s2)
/* BB07CC 80242E8C 14500021 */  bne       $v0, $s0, .L80242F14
/* BB07D0 80242E90 00000000 */   nop      
.L80242E94:
/* BB07D4 80242E94 0240202D */  daddu     $a0, $s2, $zero
/* BB07D8 80242E98 0260282D */  daddu     $a1, $s3, $zero
/* BB07DC 80242E9C 0C090A84 */  jal       func_80242A10_BB0350
/* BB07E0 80242EA0 0280302D */   daddu    $a2, $s4, $zero
/* BB07E4 80242EA4 8E430070 */  lw        $v1, 0x70($s2)
/* BB07E8 80242EA8 2402000C */  addiu     $v0, $zero, 0xc
/* BB07EC 80242EAC 14620019 */  bne       $v1, $v0, .L80242F14
/* BB07F0 80242EB0 00000000 */   nop      
/* BB07F4 80242EB4 0240202D */  daddu     $a0, $s2, $zero
.L80242EB8:
/* BB07F8 80242EB8 0260282D */  daddu     $a1, $s3, $zero
/* BB07FC 80242EBC 0C090AA8 */  jal       func_80242AA0_BB03E0
/* BB0800 80242EC0 0280302D */   daddu    $a2, $s4, $zero
/* BB0804 80242EC4 8E430070 */  lw        $v1, 0x70($s2)
/* BB0808 80242EC8 2402000D */  addiu     $v0, $zero, 0xd
/* BB080C 80242ECC 14620011 */  bne       $v1, $v0, .L80242F14
/* BB0810 80242ED0 00000000 */   nop      
.L80242ED4:
/* BB0814 80242ED4 0240202D */  daddu     $a0, $s2, $zero
/* BB0818 80242ED8 0260282D */  daddu     $a1, $s3, $zero
/* BB081C 80242EDC 0C090AE8 */  jal       pause_set_cursor_opacity
/* BB0820 80242EE0 0280302D */   daddu    $a2, $s4, $zero
/* BB0824 80242EE4 8E430070 */  lw        $v1, 0x70($s2)
/* BB0828 80242EE8 2402000E */  addiu     $v0, $zero, 0xe
/* BB082C 80242EEC 14620009 */  bne       $v1, $v0, .L80242F14
/* BB0830 80242EF0 00000000 */   nop      
/* BB0834 80242EF4 0240202D */  daddu     $a0, $s2, $zero
.L80242EF8:
/* BB0838 80242EF8 0260282D */  daddu     $a1, $s3, $zero
/* BB083C 80242EFC 0C090B00 */  jal       func_80242C00_BB0540
/* BB0840 80242F00 0280302D */   daddu    $a2, $s4, $zero
/* BB0844 80242F04 08090BC5 */  j         .L80242F14
/* BB0848 80242F08 00000000 */   nop      
.L80242F0C:
/* BB084C 80242F0C 0C0129CF */  jal       func_8004A73C
/* BB0850 80242F10 0240202D */   daddu    $a0, $s2, $zero
.L80242F14:
/* BB0854 80242F14 8FBF0048 */  lw        $ra, 0x48($sp)
/* BB0858 80242F18 8FB50044 */  lw        $s5, 0x44($sp)
/* BB085C 80242F1C 8FB40040 */  lw        $s4, 0x40($sp)
/* BB0860 80242F20 8FB3003C */  lw        $s3, 0x3c($sp)
/* BB0864 80242F24 8FB20038 */  lw        $s2, 0x38($sp)
/* BB0868 80242F28 8FB10034 */  lw        $s1, 0x34($sp)
/* BB086C 80242F2C 8FB00030 */  lw        $s0, 0x30($sp)
/* BB0870 80242F30 0000102D */  daddu     $v0, $zero, $zero
/* BB0874 80242F34 03E00008 */  jr        $ra
/* BB0878 80242F38 27BD0050 */   addiu    $sp, $sp, 0x50
/* BB087C 80242F3C 00000000 */  nop       
