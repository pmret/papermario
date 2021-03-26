.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80151290
.word L8014A7A0_E0EA0, L8014A5AC_E0CAC, L8014A64C_E0D4C, L8014A68C_E0D8C, L8014A644_E0D44, L8014A698_E0D98, 0, 0

.section .text

glabel bgm_update_music_settings
/* E0C48 8014A548 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* E0C4C 8014A54C AFB1001C */  sw        $s1, 0x1c($sp)
/* E0C50 8014A550 3C118016 */  lui       $s1, %hi(gMusicPlayers)
/* E0C54 8014A554 26319AF0 */  addiu     $s1, $s1, %lo(gMusicPlayers)
/* E0C58 8014A558 AFB20020 */  sw        $s2, 0x20($sp)
/* E0C5C 8014A55C 0000902D */  daddu     $s2, $zero, $zero
/* E0C60 8014A560 AFB30024 */  sw        $s3, 0x24($sp)
/* E0C64 8014A564 24130002 */  addiu     $s3, $zero, 2
/* E0C68 8014A568 AFB5002C */  sw        $s5, 0x2c($sp)
/* E0C6C 8014A56C 2415FFFB */  addiu     $s5, $zero, -5
/* E0C70 8014A570 AFB40028 */  sw        $s4, 0x28($sp)
/* E0C74 8014A574 24140005 */  addiu     $s4, $zero, 5
/* E0C78 8014A578 AFB00018 */  sw        $s0, 0x18($sp)
/* E0C7C 8014A57C 26300002 */  addiu     $s0, $s1, 2
/* E0C80 8014A580 AFBF0030 */  sw        $ra, 0x30($sp)
.L8014A584:
/* E0C84 8014A584 86030000 */  lh        $v1, ($s0)
/* E0C88 8014A588 2C620006 */  sltiu     $v0, $v1, 6
/* E0C8C 8014A58C 50400085 */  beql      $v0, $zero, .L8014A7A4
/* E0C90 8014A590 26520001 */   addiu    $s2, $s2, 1
/* E0C94 8014A594 00031080 */  sll       $v0, $v1, 2
/* E0C98 8014A598 3C018015 */  lui       $at, %hi(jtbl_80151290)
/* E0C9C 8014A59C 00220821 */  addu      $at, $at, $v0
/* E0CA0 8014A5A0 8C221290 */  lw        $v0, %lo(jtbl_80151290)($at)
/* E0CA4 8014A5A4 00400008 */  jr        $v0
/* E0CA8 8014A5A8 00000000 */   nop
glabel L8014A5AC_E0CAC
/* E0CAC 8014A5AC 96230000 */  lhu       $v1, ($s1)
/* E0CB0 8014A5B0 30620001 */  andi      $v0, $v1, 1
/* E0CB4 8014A5B4 1040001D */  beqz      $v0, .L8014A62C
/* E0CB8 8014A5B8 30620004 */   andi     $v0, $v1, 4
/* E0CBC 8014A5BC 8E050002 */  lw        $a1, 2($s0)
/* E0CC0 8014A5C0 28A200FA */  slti      $v0, $a1, 0xfa
/* E0CC4 8014A5C4 1040000B */  beqz      $v0, .L8014A5F4
/* E0CC8 8014A5C8 30620004 */   andi     $v0, $v1, 4
/* E0CCC 8014A5CC 14400005 */  bnez      $v0, .L8014A5E4
/* E0CD0 8014A5D0 00000000 */   nop
/* E0CD4 8014A5D4 0C015671 */  jal       func_800559C4
/* E0CD8 8014A5D8 8E040016 */   lw       $a0, 0x16($s0)
/* E0CDC 8014A5DC 08052987 */  j         .L8014A61C
/* E0CE0 8014A5E0 00000000 */   nop
.L8014A5E4:
/* E0CE4 8014A5E4 0C0156BC */  jal       func_80055AF0
/* E0CE8 8014A5E8 8E040016 */   lw       $a0, 0x16($s0)
/* E0CEC 8014A5EC 08052987 */  j         .L8014A61C
/* E0CF0 8014A5F0 00000000 */   nop
.L8014A5F4:
/* E0CF4 8014A5F4 14400006 */  bnez      $v0, .L8014A610
/* E0CF8 8014A5F8 00000000 */   nop
/* E0CFC 8014A5FC 8E040016 */  lw        $a0, 0x16($s0)
/* E0D00 8014A600 0C0156AF */  jal       func_80055ABC
/* E0D04 8014A604 0000302D */   daddu    $a2, $zero, $zero
/* E0D08 8014A608 08052987 */  j         .L8014A61C
/* E0D0C 8014A60C 00000000 */   nop
.L8014A610:
/* E0D10 8014A610 8E040016 */  lw        $a0, 0x16($s0)
/* E0D14 8014A614 0C0156EE */  jal       func_80055BB8
/* E0D18 8014A618 240500FA */   addiu    $a1, $zero, 0xfa
.L8014A61C:
/* E0D1C 8014A61C 50400060 */  beql      $v0, $zero, L8014A7A0_E0EA0
/* E0D20 8014A620 A6130000 */   sh       $s3, ($s0)
/* E0D24 8014A624 080529E9 */  j         .L8014A7A4
/* E0D28 8014A628 26520001 */   addiu    $s2, $s2, 1
.L8014A62C:
/* E0D2C 8014A62C 10400002 */  beqz      $v0, .L8014A638
/* E0D30 8014A630 34620010 */   ori      $v0, $v1, 0x10
/* E0D34 8014A634 A6220000 */  sh        $v0, ($s1)
.L8014A638:
/* E0D38 8014A638 96220000 */  lhu       $v0, ($s1)
/* E0D3C 8014A63C 00551024 */  and       $v0, $v0, $s5
/* E0D40 8014A640 A6220000 */  sh        $v0, ($s1)
glabel L8014A644_E0D44
/* E0D44 8014A644 080529E8 */  j         L8014A7A0_E0EA0
/* E0D48 8014A648 A6140000 */   sh       $s4, ($s0)
glabel L8014A64C_E0D4C
/* E0D4C 8014A64C 96230000 */  lhu       $v1, ($s1)
/* E0D50 8014A650 00751024 */  and       $v0, $v1, $s5
/* E0D54 8014A654 30630001 */  andi      $v1, $v1, 1
/* E0D58 8014A658 1060FFFA */  beqz      $v1, L8014A644_E0D44
/* E0D5C 8014A65C A6220000 */   sh       $v0, ($s1)
/* E0D60 8014A660 8E040016 */  lw        $a0, 0x16($s0)
/* E0D64 8014A664 0C01567F */  jal       func_800559FC
/* E0D68 8014A668 00000000 */   nop
/* E0D6C 8014A66C 5440004D */  bnel      $v0, $zero, .L8014A7A4
/* E0D70 8014A670 26520001 */   addiu    $s2, $s2, 1
/* E0D74 8014A674 96220000 */  lhu       $v0, ($s1)
/* E0D78 8014A678 3042FFFE */  andi      $v0, $v0, 0xfffe
/* E0D7C 8014A67C A6220000 */  sh        $v0, ($s1)
/* E0D80 8014A680 24020003 */  addiu     $v0, $zero, 3
/* E0D84 8014A684 080529E8 */  j         L8014A7A0_E0EA0
/* E0D88 8014A688 A6020000 */   sh       $v0, ($s0)
glabel L8014A68C_E0D8C
/* E0D8C 8014A68C 24020004 */  addiu     $v0, $zero, 4
/* E0D90 8014A690 080529E8 */  j         L8014A7A0_E0EA0
/* E0D94 8014A694 A6020000 */   sh       $v0, ($s0)
glabel L8014A698_E0D98
/* E0D98 8014A698 96230000 */  lhu       $v1, ($s1)
/* E0D9C 8014A69C 30620008 */  andi      $v0, $v1, 8
/* E0DA0 8014A6A0 14400029 */  bnez      $v0, .L8014A748
/* E0DA4 8014A6A4 30620010 */   andi     $v0, $v1, 0x10
/* E0DA8 8014A6A8 8E04000E */  lw        $a0, 0xe($s0)
/* E0DAC 8014A6AC 04810003 */  bgez      $a0, .L8014A6BC
/* E0DB0 8014A6B0 00000000 */   nop
/* E0DB4 8014A6B4 080529E8 */  j         L8014A7A0_E0EA0
/* E0DB8 8014A6B8 A6000000 */   sh       $zero, ($s0)
.L8014A6BC:
/* E0DBC 8014A6BC 0C015635 */  jal       func_800558D4
/* E0DC0 8014A6C0 0240282D */   daddu    $a1, $s2, $zero
/* E0DC4 8014A6C4 3403FFFF */  ori       $v1, $zero, 0xffff
/* E0DC8 8014A6C8 0062182B */  sltu      $v1, $v1, $v0
/* E0DCC 8014A6CC 10600034 */  beqz      $v1, L8014A7A0_E0EA0
/* E0DD0 8014A6D0 AE020016 */   sw       $v0, 0x16($s0)
/* E0DD4 8014A6D4 96220000 */  lhu       $v0, ($s1)
/* E0DD8 8014A6D8 30420020 */  andi      $v0, $v0, 0x20
/* E0DDC 8014A6DC 1040000C */  beqz      $v0, .L8014A710
/* E0DE0 8014A6E0 00000000 */   nop
/* E0DE4 8014A6E4 8602000C */  lh        $v0, 0xc($s0)
/* E0DE8 8014A6E8 8607000A */  lh        $a3, 0xa($s0)
/* E0DEC 8014A6EC AFA20010 */  sw        $v0, 0x10($sp)
/* E0DF0 8014A6F0 8E040016 */  lw        $a0, 0x16($s0)
/* E0DF4 8014A6F4 8E050012 */  lw        $a1, 0x12($s0)
/* E0DF8 8014A6F8 0C015686 */  jal       func_80055A18
/* E0DFC 8014A6FC 8E060006 */   lw       $a2, 6($s0)
/* E0E00 8014A700 96220000 */  lhu       $v0, ($s1)
/* E0E04 8014A704 3042FFDF */  andi      $v0, $v0, 0xffdf
/* E0E08 8014A708 080529C8 */  j         .L8014A720
/* E0E0C 8014A70C A6220000 */   sh       $v0, ($s1)
.L8014A710:
/* E0E10 8014A710 3C048016 */  lui       $a0, %hi(gMusicUnkVolume)
/* E0E14 8014A714 84849AE0 */  lh        $a0, %lo(gMusicUnkVolume)($a0)
/* E0E18 8014A718 0C052B21 */  jal       bgm_set_target_volume
/* E0E1C 8014A71C 00000000 */   nop
.L8014A720:
/* E0E20 8014A720 8E040016 */  lw        $a0, 0x16($s0)
/* E0E24 8014A724 0C01565C */  jal       func_80055970
/* E0E28 8014A728 8E050012 */   lw       $a1, 0x12($s0)
/* E0E2C 8014A72C 5440001D */  bnel      $v0, $zero, .L8014A7A4
/* E0E30 8014A730 26520001 */   addiu    $s2, $s2, 1
/* E0E34 8014A734 96220000 */  lhu       $v0, ($s1)
/* E0E38 8014A738 34420001 */  ori       $v0, $v0, 1
/* E0E3C 8014A73C A6220000 */  sh        $v0, ($s1)
/* E0E40 8014A740 080529E8 */  j         L8014A7A0_E0EA0
/* E0E44 8014A744 A6000000 */   sh       $zero, ($s0)
.L8014A748:
/* E0E48 8014A748 10400005 */  beqz      $v0, .L8014A760
/* E0E4C 8014A74C 00000000 */   nop
/* E0E50 8014A750 A6000000 */  sh        $zero, ($s0)
/* E0E54 8014A754 96220000 */  lhu       $v0, ($s1)
/* E0E58 8014A758 080529E7 */  j         .L8014A79C
/* E0E5C 8014A75C 3042FFE7 */   andi     $v0, $v0, 0xffe7
.L8014A760:
/* E0E60 8014A760 8E04002A */  lw        $a0, 0x2a($s0)
/* E0E64 8014A764 0C0156CA */  jal       func_80055B28
/* E0E68 8014A768 00000000 */   nop
/* E0E6C 8014A76C 5440000D */  bnel      $v0, $zero, .L8014A7A4
/* E0E70 8014A770 26520001 */   addiu    $s2, $s2, 1
/* E0E74 8014A774 8E020022 */  lw        $v0, 0x22($s0)
/* E0E78 8014A778 8E030026 */  lw        $v1, 0x26($s0)
/* E0E7C 8014A77C 8E04002A */  lw        $a0, 0x2a($s0)
/* E0E80 8014A780 A6000000 */  sh        $zero, ($s0)
/* E0E84 8014A784 AE02000E */  sw        $v0, 0xe($s0)
/* E0E88 8014A788 AE030012 */  sw        $v1, 0x12($s0)
/* E0E8C 8014A78C AE040016 */  sw        $a0, 0x16($s0)
/* E0E90 8014A790 96220000 */  lhu       $v0, ($s1)
/* E0E94 8014A794 34420001 */  ori       $v0, $v0, 1
/* E0E98 8014A798 3042FFF7 */  andi      $v0, $v0, 0xfff7
.L8014A79C:
/* E0E9C 8014A79C A6220000 */  sh        $v0, ($s1)
glabel L8014A7A0_E0EA0
/* E0EA0 8014A7A0 26520001 */  addiu     $s2, $s2, 1
.L8014A7A4:
/* E0EA4 8014A7A4 26100030 */  addiu     $s0, $s0, 0x30
/* E0EA8 8014A7A8 2A420002 */  slti      $v0, $s2, 2
/* E0EAC 8014A7AC 1440FF75 */  bnez      $v0, .L8014A584
/* E0EB0 8014A7B0 26310030 */   addiu    $s1, $s1, 0x30
/* E0EB4 8014A7B4 0C052B25 */  jal       bgm_update_volume
/* E0EB8 8014A7B8 00000000 */   nop
/* E0EBC 8014A7BC 8FBF0030 */  lw        $ra, 0x30($sp)
/* E0EC0 8014A7C0 8FB5002C */  lw        $s5, 0x2c($sp)
/* E0EC4 8014A7C4 8FB40028 */  lw        $s4, 0x28($sp)
/* E0EC8 8014A7C8 8FB30024 */  lw        $s3, 0x24($sp)
/* E0ECC 8014A7CC 8FB20020 */  lw        $s2, 0x20($sp)
/* E0ED0 8014A7D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* E0ED4 8014A7D4 8FB00018 */  lw        $s0, 0x18($sp)
/* E0ED8 8014A7D8 03E00008 */  jr        $ra
/* E0EDC 8014A7DC 27BD0038 */   addiu    $sp, $sp, 0x38
