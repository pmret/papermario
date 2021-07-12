.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80150030
.word L80120748_B6E48, L80120768_B6E68, L80120B7C_B727C, L80120778_B6E78, L80120798_B6E98, L80120870_B6F70, L8012093C_B703C, L80120B7C_B727C, L80120A20_B7120, L80120B7C_B727C, L801207AC_B6EAC, L80120B7C_B727C, L80120B7C_B727C, L80120B7C_B727C, L801207C4_B6EC4, L801207E0_B6EE0, L80120814_B6F14, L80120AA0_B71A0, L80120750_B6E50, L80120854_B6F54

glabel D_80150080
.double 180.0

glabel D_80150088
.double 32767.0

glabel D_80150090
.double 180.0

glabel D_80150098
.double 32767.0

glabel D_801500A0
.double 180.0

glabel D_801500A8
.double 32767.0

.section .text

glabel step_mesh_animator
/* B6DF8 801206F8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B6DFC 801206FC AFB10014 */  sw        $s1, 0x14($sp)
/* B6E00 80120700 0080882D */  daddu     $s1, $a0, $zero
/* B6E04 80120704 AFBF001C */  sw        $ra, 0x1c($sp)
/* B6E08 80120708 AFB20018 */  sw        $s2, 0x18($sp)
/* B6E0C 8012070C AFB00010 */  sw        $s0, 0x10($sp)
/* B6E10 80120710 F7B80030 */  sdc1      $f24, 0x30($sp)
/* B6E14 80120714 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B6E18 80120718 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B6E1C 8012071C 8E320008 */  lw        $s2, 8($s1)
/* B6E20 80120720 86430000 */  lh        $v1, ($s2)
/* B6E24 80120724 2C620014 */  sltiu     $v0, $v1, 0x14
/* B6E28 80120728 10400114 */  beqz      $v0, L80120B7C_B727C
/* B6E2C 8012072C 26500002 */   addiu    $s0, $s2, 2
/* B6E30 80120730 00031080 */  sll       $v0, $v1, 2
/* B6E34 80120734 3C018015 */  lui       $at, %hi(jtbl_80150030)
/* B6E38 80120738 00220821 */  addu      $at, $at, $v0
/* B6E3C 8012073C 8C220030 */  lw        $v0, %lo(jtbl_80150030)($at)
/* B6E40 80120740 00400008 */  jr        $v0
/* B6E44 80120744 00000000 */   nop
glabel L80120748_B6E48
/* B6E48 80120748 080482E0 */  j         .L80120B80
/* B6E4C 8012074C 2402FFFF */   addiu    $v0, $zero, -1
glabel L80120750_B6E50
/* B6E50 80120750 92030001 */  lbu       $v1, 1($s0)
/* B6E54 80120754 26100002 */  addiu     $s0, $s0, 2
/* B6E58 80120758 24020001 */  addiu     $v0, $zero, 1
/* B6E5C 8012075C AE300008 */  sw        $s0, 8($s1)
/* B6E60 80120760 080482E0 */  j         .L80120B80
/* B6E64 80120764 A2230004 */   sb       $v1, 4($s1)
glabel L80120768_B6E68
/* B6E68 80120768 26100002 */  addiu     $s0, $s0, 2
/* B6E6C 8012076C AE300008 */  sw        $s0, 8($s1)
.L80120770:
/* B6E70 80120770 080482E0 */  j         .L80120B80
/* B6E74 80120774 24020001 */   addiu    $v0, $zero, 1
glabel L80120778_B6E78
/* B6E78 80120778 8E22000C */  lw        $v0, 0xc($s1)
/* B6E7C 8012077C 8E2302D0 */  lw        $v1, 0x2d0($s1)
/* B6E80 80120780 0220202D */  daddu     $a0, $s1, $zero
/* B6E84 80120784 AC820008 */  sw        $v0, 8($a0)
/* B6E88 80120788 0C04819E */  jal       reload_mesh_animator_tree
/* B6E8C 8012078C AC8302CC */   sw       $v1, 0x2cc($a0)
/* B6E90 80120790 080482E0 */  j         .L80120B80
/* B6E94 80120794 24020001 */   addiu    $v0, $zero, 1
glabel L80120798_B6E98
/* B6E98 80120798 8E22000C */  lw        $v0, 0xc($s1)
/* B6E9C 8012079C 8E2302D0 */  lw        $v1, 0x2d0($s1)
/* B6EA0 801207A0 AE220008 */  sw        $v0, 8($s1)
/* B6EA4 801207A4 080482DF */  j         L80120B7C_B727C
/* B6EA8 801207A8 AE2302CC */   sw       $v1, 0x2cc($s1)
glabel L801207AC_B6EAC
/* B6EAC 801207AC 8E2302CC */  lw        $v1, 0x2cc($s1)
/* B6EB0 801207B0 24020001 */  addiu     $v0, $zero, 1
/* B6EB4 801207B4 AE30000C */  sw        $s0, 0xc($s1)
/* B6EB8 801207B8 AE300008 */  sw        $s0, 8($s1)
/* B6EBC 801207BC 080482E0 */  j         .L80120B80
/* B6EC0 801207C0 AE2302D0 */   sw       $v1, 0x2d0($s1)
glabel L801207C4_B6EC4
/* B6EC4 801207C4 86040000 */  lh        $a0, ($s0)
/* B6EC8 801207C8 26100002 */  addiu     $s0, $s0, 2
/* B6ECC 801207CC 8E230000 */  lw        $v1, ($s1)
/* B6ED0 801207D0 24020001 */  addiu     $v0, $zero, 1
/* B6ED4 801207D4 AE300008 */  sw        $s0, 8($s1)
/* B6ED8 801207D8 08048219 */  j         .L80120864
/* B6EDC 801207DC 3084FFFF */   andi     $a0, $a0, 0xffff
glabel L801207E0_B6EE0
/* B6EE0 801207E0 86020000 */  lh        $v0, ($s0)
/* B6EE4 801207E4 8E240010 */  lw        $a0, 0x10($s1)
/* B6EE8 801207E8 00511021 */  addu      $v0, $v0, $s1
/* B6EEC 801207EC 90450014 */  lbu       $a1, 0x14($v0)
/* B6EF0 801207F0 0C047837 */  jal       get_animator_child_with_id
/* B6EF4 801207F4 26100002 */   addiu    $s0, $s0, 2
/* B6EF8 801207F8 0040282D */  daddu     $a1, $v0, $zero
/* B6EFC 801207FC 86040000 */  lh        $a0, ($s0)
/* B6F00 80120800 26100002 */  addiu     $s0, $s0, 2
/* B6F04 80120804 94A300F4 */  lhu       $v1, 0xf4($a1)
/* B6F08 80120808 24020001 */  addiu     $v0, $zero, 1
/* B6F0C 8012080C 08048212 */  j         .L80120848
/* B6F10 80120810 00641825 */   or       $v1, $v1, $a0
glabel L80120814_B6F14
/* B6F14 80120814 86020000 */  lh        $v0, ($s0)
/* B6F18 80120818 8E240010 */  lw        $a0, 0x10($s1)
/* B6F1C 8012081C 00511021 */  addu      $v0, $v0, $s1
/* B6F20 80120820 90450014 */  lbu       $a1, 0x14($v0)
/* B6F24 80120824 0C047837 */  jal       get_animator_child_with_id
/* B6F28 80120828 26100002 */   addiu    $s0, $s0, 2
/* B6F2C 8012082C 0040282D */  daddu     $a1, $v0, $zero
/* B6F30 80120830 86040000 */  lh        $a0, ($s0)
/* B6F34 80120834 26100002 */  addiu     $s0, $s0, 2
/* B6F38 80120838 24020001 */  addiu     $v0, $zero, 1
/* B6F3C 8012083C 94A300F4 */  lhu       $v1, 0xf4($a1)
/* B6F40 80120840 00042027 */  nor       $a0, $zero, $a0
/* B6F44 80120844 00641824 */  and       $v1, $v1, $a0
.L80120848:
/* B6F48 80120848 A4A300F4 */  sh        $v1, 0xf4($a1)
/* B6F4C 8012084C 080482E0 */  j         .L80120B80
/* B6F50 80120850 AE300008 */   sw       $s0, 8($s1)
glabel L80120854_B6F54
/* B6F54 80120854 24020001 */  addiu     $v0, $zero, 1
/* B6F58 80120858 8E230000 */  lw        $v1, ($s1)
/* B6F5C 8012085C 3C040002 */  lui       $a0, 2
/* B6F60 80120860 AE300008 */  sw        $s0, 8($s1)
.L80120864:
/* B6F64 80120864 00641825 */  or        $v1, $v1, $a0
/* B6F68 80120868 080482E0 */  j         .L80120B80
/* B6F6C 8012086C AE230000 */   sw       $v1, ($s1)
glabel L80120870_B6F70
/* B6F70 80120870 86030000 */  lh        $v1, ($s0)
/* B6F74 80120874 26100002 */  addiu     $s0, $s0, 2
/* B6F78 80120878 86020000 */  lh        $v0, ($s0)
/* B6F7C 8012087C 3C018015 */  lui       $at, %hi(D_80150080)
/* B6F80 80120880 D4260080 */  ldc1      $f6, %lo(D_80150080)($at)
/* B6F84 80120884 44822000 */  mtc1      $v0, $f4
/* B6F88 80120888 00000000 */  nop
/* B6F8C 8012088C 46802120 */  cvt.s.w   $f4, $f4
/* B6F90 80120890 46002121 */  cvt.d.s   $f4, $f4
/* B6F94 80120894 46262102 */  mul.d     $f4, $f4, $f6
/* B6F98 80120898 00000000 */  nop
/* B6F9C 8012089C 26100002 */  addiu     $s0, $s0, 2
/* B6FA0 801208A0 86020000 */  lh        $v0, ($s0)
/* B6FA4 801208A4 44821000 */  mtc1      $v0, $f2
/* B6FA8 801208A8 00000000 */  nop
/* B6FAC 801208AC 468010A0 */  cvt.s.w   $f2, $f2
/* B6FB0 801208B0 460010A1 */  cvt.d.s   $f2, $f2
/* B6FB4 801208B4 46261082 */  mul.d     $f2, $f2, $f6
/* B6FB8 801208B8 00000000 */  nop
/* B6FBC 801208BC 26100002 */  addiu     $s0, $s0, 2
/* B6FC0 801208C0 00711821 */  addu      $v1, $v1, $s1
/* B6FC4 801208C4 90630014 */  lbu       $v1, 0x14($v1)
/* B6FC8 801208C8 86020000 */  lh        $v0, ($s0)
/* B6FCC 801208CC 26100002 */  addiu     $s0, $s0, 2
/* B6FD0 801208D0 44820000 */  mtc1      $v0, $f0
/* B6FD4 801208D4 00000000 */  nop
/* B6FD8 801208D8 46800020 */  cvt.s.w   $f0, $f0
/* B6FDC 801208DC 46000021 */  cvt.d.s   $f0, $f0
/* B6FE0 801208E0 46260002 */  mul.d     $f0, $f0, $f6
/* B6FE4 801208E4 00000000 */  nop
/* B6FE8 801208E8 AE300008 */  sw        $s0, 8($s1)
/* B6FEC 801208EC 3C018015 */  lui       $at, %hi(D_80150088)
/* B6FF0 801208F0 D4260088 */  ldc1      $f6, %lo(D_80150088)($at)
/* B6FF4 801208F4 240200FF */  addiu     $v0, $zero, 0xff
/* B6FF8 801208F8 46262103 */  div.d     $f4, $f4, $f6
/* B6FFC 801208FC 46202620 */  cvt.s.d   $f24, $f4
/* B7000 80120900 46261083 */  div.d     $f2, $f2, $f6
/* B7004 80120904 462015A0 */  cvt.s.d   $f22, $f2
/* B7008 80120908 46260003 */  div.d     $f0, $f0, $f6
/* B700C 8012090C 1062FF98 */  beq       $v1, $v0, .L80120770
/* B7010 80120910 46200520 */   cvt.s.d  $f20, $f0
/* B7014 80120914 8E240010 */  lw        $a0, 0x10($s1)
/* B7018 80120918 0C047837 */  jal       get_animator_child_with_id
/* B701C 8012091C 0060282D */   daddu    $a1, $v1, $zero
/* B7020 80120920 0040282D */  daddu     $a1, $v0, $zero
/* B7024 80120924 10A00091 */  beqz      $a1, .L80120B6C
/* B7028 80120928 24020001 */   addiu    $v0, $zero, 1
/* B702C 8012092C E4B8009C */  swc1      $f24, 0x9c($a1)
/* B7030 80120930 E4B600A0 */  swc1      $f22, 0xa0($a1)
/* B7034 80120934 080482E0 */  j         .L80120B80
/* B7038 80120938 E4B400A4 */   swc1     $f20, 0xa4($a1)
glabel L8012093C_B703C
/* B703C 8012093C 86030000 */  lh        $v1, ($s0)
/* B7040 80120940 26100002 */  addiu     $s0, $s0, 2
/* B7044 80120944 86020000 */  lh        $v0, ($s0)
/* B7048 80120948 3C018015 */  lui       $at, %hi(D_80150090)
/* B704C 8012094C D4260090 */  ldc1      $f6, %lo(D_80150090)($at)
/* B7050 80120950 44822000 */  mtc1      $v0, $f4
/* B7054 80120954 00000000 */  nop
/* B7058 80120958 46802120 */  cvt.s.w   $f4, $f4
/* B705C 8012095C 46002121 */  cvt.d.s   $f4, $f4
/* B7060 80120960 46262102 */  mul.d     $f4, $f4, $f6
/* B7064 80120964 00000000 */  nop
/* B7068 80120968 26100002 */  addiu     $s0, $s0, 2
/* B706C 8012096C 86020000 */  lh        $v0, ($s0)
/* B7070 80120970 44821000 */  mtc1      $v0, $f2
/* B7074 80120974 00000000 */  nop
/* B7078 80120978 468010A0 */  cvt.s.w   $f2, $f2
/* B707C 8012097C 460010A1 */  cvt.d.s   $f2, $f2
/* B7080 80120980 46261082 */  mul.d     $f2, $f2, $f6
/* B7084 80120984 00000000 */  nop
/* B7088 80120988 26100002 */  addiu     $s0, $s0, 2
/* B708C 8012098C 00711821 */  addu      $v1, $v1, $s1
/* B7090 80120990 90630014 */  lbu       $v1, 0x14($v1)
/* B7094 80120994 86020000 */  lh        $v0, ($s0)
/* B7098 80120998 26100002 */  addiu     $s0, $s0, 2
/* B709C 8012099C 44820000 */  mtc1      $v0, $f0
/* B70A0 801209A0 00000000 */  nop
/* B70A4 801209A4 46800020 */  cvt.s.w   $f0, $f0
/* B70A8 801209A8 46000021 */  cvt.d.s   $f0, $f0
/* B70AC 801209AC 46260002 */  mul.d     $f0, $f0, $f6
/* B70B0 801209B0 00000000 */  nop
/* B70B4 801209B4 AE300008 */  sw        $s0, 8($s1)
/* B70B8 801209B8 3C018015 */  lui       $at, %hi(D_80150098)
/* B70BC 801209BC D4260098 */  ldc1      $f6, %lo(D_80150098)($at)
/* B70C0 801209C0 240200FF */  addiu     $v0, $zero, 0xff
/* B70C4 801209C4 46262103 */  div.d     $f4, $f4, $f6
/* B70C8 801209C8 46202620 */  cvt.s.d   $f24, $f4
/* B70CC 801209CC 46261083 */  div.d     $f2, $f2, $f6
/* B70D0 801209D0 462015A0 */  cvt.s.d   $f22, $f2
/* B70D4 801209D4 46260003 */  div.d     $f0, $f0, $f6
/* B70D8 801209D8 1062FF65 */  beq       $v1, $v0, .L80120770
/* B70DC 801209DC 46200520 */   cvt.s.d  $f20, $f0
/* B70E0 801209E0 8E240010 */  lw        $a0, 0x10($s1)
/* B70E4 801209E4 0C047837 */  jal       get_animator_child_with_id
/* B70E8 801209E8 0060282D */   daddu    $a1, $v1, $zero
/* B70EC 801209EC 0040282D */  daddu     $a1, $v0, $zero
/* B70F0 801209F0 10A0005E */  beqz      $a1, .L80120B6C
/* B70F4 801209F4 24020001 */   addiu    $v0, $zero, 1
/* B70F8 801209F8 C4A4009C */  lwc1      $f4, 0x9c($a1)
/* B70FC 801209FC 46182100 */  add.s     $f4, $f4, $f24
/* B7100 80120A00 C4A200A0 */  lwc1      $f2, 0xa0($a1)
/* B7104 80120A04 46161080 */  add.s     $f2, $f2, $f22
/* B7108 80120A08 C4A000A4 */  lwc1      $f0, 0xa4($a1)
/* B710C 80120A0C 46140000 */  add.s     $f0, $f0, $f20
/* B7110 80120A10 E4A4009C */  swc1      $f4, 0x9c($a1)
/* B7114 80120A14 E4A200A0 */  swc1      $f2, 0xa0($a1)
/* B7118 80120A18 080482E0 */  j         .L80120B80
/* B711C 80120A1C E4A000A4 */   swc1     $f0, 0xa4($a1)
glabel L80120A20_B7120
/* B7120 80120A20 86020000 */  lh        $v0, ($s0)
/* B7124 80120A24 26100002 */  addiu     $s0, $s0, 2
/* B7128 80120A28 86040000 */  lh        $a0, ($s0)
/* B712C 80120A2C 26100002 */  addiu     $s0, $s0, 2
/* B7130 80120A30 86030000 */  lh        $v1, ($s0)
/* B7134 80120A34 26100002 */  addiu     $s0, $s0, 2
/* B7138 80120A38 86050000 */  lh        $a1, ($s0)
/* B713C 80120A3C 26100002 */  addiu     $s0, $s0, 2
/* B7140 80120A40 4484C000 */  mtc1      $a0, $f24
/* B7144 80120A44 00000000 */  nop
/* B7148 80120A48 4680C620 */  cvt.s.w   $f24, $f24
/* B714C 80120A4C 4483B000 */  mtc1      $v1, $f22
/* B7150 80120A50 00000000 */  nop
/* B7154 80120A54 4680B5A0 */  cvt.s.w   $f22, $f22
/* B7158 80120A58 00511021 */  addu      $v0, $v0, $s1
/* B715C 80120A5C 4485A000 */  mtc1      $a1, $f20
/* B7160 80120A60 00000000 */  nop
/* B7164 80120A64 4680A520 */  cvt.s.w   $f20, $f20
/* B7168 80120A68 90430014 */  lbu       $v1, 0x14($v0)
/* B716C 80120A6C 240200FF */  addiu     $v0, $zero, 0xff
/* B7170 80120A70 1062FF3F */  beq       $v1, $v0, .L80120770
/* B7174 80120A74 AE300008 */   sw       $s0, 8($s1)
/* B7178 80120A78 8E240010 */  lw        $a0, 0x10($s1)
/* B717C 80120A7C 0C047837 */  jal       get_animator_child_with_id
/* B7180 80120A80 0060282D */   daddu    $a1, $v1, $zero
/* B7184 80120A84 0040282D */  daddu     $a1, $v0, $zero
/* B7188 80120A88 10A00038 */  beqz      $a1, .L80120B6C
/* B718C 80120A8C 24020001 */   addiu    $v0, $zero, 1
/* B7190 80120A90 E4B80090 */  swc1      $f24, 0x90($a1)
/* B7194 80120A94 E4B60094 */  swc1      $f22, 0x94($a1)
/* B7198 80120A98 080482E0 */  j         .L80120B80
/* B719C 80120A9C E4B40098 */   swc1     $f20, 0x98($a1)
glabel L80120AA0_B71A0
/* B71A0 80120AA0 86030000 */  lh        $v1, ($s0)
/* B71A4 80120AA4 26100002 */  addiu     $s0, $s0, 2
/* B71A8 80120AA8 86020000 */  lh        $v0, ($s0)
/* B71AC 80120AAC 3C018015 */  lui       $at, %hi(D_801500A0)
/* B71B0 80120AB0 D42600A0 */  ldc1      $f6, %lo(D_801500A0)($at)
/* B71B4 80120AB4 44822000 */  mtc1      $v0, $f4
/* B71B8 80120AB8 00000000 */  nop
/* B71BC 80120ABC 46802120 */  cvt.s.w   $f4, $f4
/* B71C0 80120AC0 46002121 */  cvt.d.s   $f4, $f4
/* B71C4 80120AC4 46262102 */  mul.d     $f4, $f4, $f6
/* B71C8 80120AC8 00000000 */  nop
/* B71CC 80120ACC 26100002 */  addiu     $s0, $s0, 2
/* B71D0 80120AD0 86020000 */  lh        $v0, ($s0)
/* B71D4 80120AD4 44821000 */  mtc1      $v0, $f2
/* B71D8 80120AD8 00000000 */  nop
/* B71DC 80120ADC 468010A0 */  cvt.s.w   $f2, $f2
/* B71E0 80120AE0 460010A1 */  cvt.d.s   $f2, $f2
/* B71E4 80120AE4 46261082 */  mul.d     $f2, $f2, $f6
/* B71E8 80120AE8 00000000 */  nop
/* B71EC 80120AEC 26100002 */  addiu     $s0, $s0, 2
/* B71F0 80120AF0 00711821 */  addu      $v1, $v1, $s1
/* B71F4 80120AF4 90630014 */  lbu       $v1, 0x14($v1)
/* B71F8 80120AF8 86020000 */  lh        $v0, ($s0)
/* B71FC 80120AFC 26100002 */  addiu     $s0, $s0, 2
/* B7200 80120B00 44820000 */  mtc1      $v0, $f0
/* B7204 80120B04 00000000 */  nop
/* B7208 80120B08 46800020 */  cvt.s.w   $f0, $f0
/* B720C 80120B0C 46000021 */  cvt.d.s   $f0, $f0
/* B7210 80120B10 46260002 */  mul.d     $f0, $f0, $f6
/* B7214 80120B14 00000000 */  nop
/* B7218 80120B18 AE300008 */  sw        $s0, 8($s1)
/* B721C 80120B1C 3C018015 */  lui       $at, %hi(D_801500A8)
/* B7220 80120B20 D42600A8 */  ldc1      $f6, %lo(D_801500A8)($at)
/* B7224 80120B24 240200FF */  addiu     $v0, $zero, 0xff
/* B7228 80120B28 46262103 */  div.d     $f4, $f4, $f6
/* B722C 80120B2C 46202620 */  cvt.s.d   $f24, $f4
/* B7230 80120B30 46261083 */  div.d     $f2, $f2, $f6
/* B7234 80120B34 462015A0 */  cvt.s.d   $f22, $f2
/* B7238 80120B38 46260003 */  div.d     $f0, $f0, $f6
/* B723C 80120B3C 1062FF0C */  beq       $v1, $v0, .L80120770
/* B7240 80120B40 46200520 */   cvt.s.d  $f20, $f0
/* B7244 80120B44 8E240010 */  lw        $a0, 0x10($s1)
/* B7248 80120B48 0C047837 */  jal       get_animator_child_with_id
/* B724C 80120B4C 0060282D */   daddu    $a1, $v1, $zero
/* B7250 80120B50 0040282D */  daddu     $a1, $v0, $zero
/* B7254 80120B54 10A00005 */  beqz      $a1, .L80120B6C
/* B7258 80120B58 24020001 */   addiu    $v0, $zero, 1
/* B725C 80120B5C E4B800A8 */  swc1      $f24, 0xa8($a1)
/* B7260 80120B60 E4B600AC */  swc1      $f22, 0xac($a1)
/* B7264 80120B64 080482E0 */  j         .L80120B80
/* B7268 80120B68 E4B400B0 */   swc1     $f20, 0xb0($a1)
.L80120B6C:
/* B726C 80120B6C 8E2202CC */  lw        $v0, 0x2cc($s1)
/* B7270 80120B70 AE320008 */  sw        $s2, 8($s1)
/* B7274 80120B74 24420001 */  addiu     $v0, $v0, 1
/* B7278 80120B78 AE2202CC */  sw        $v0, 0x2cc($s1)
glabel L80120B7C_B727C
/* B727C 80120B7C 0000102D */  daddu     $v0, $zero, $zero
.L80120B80:
/* B7280 80120B80 8FBF001C */  lw        $ra, 0x1c($sp)
/* B7284 80120B84 8FB20018 */  lw        $s2, 0x18($sp)
/* B7288 80120B88 8FB10014 */  lw        $s1, 0x14($sp)
/* B728C 80120B8C 8FB00010 */  lw        $s0, 0x10($sp)
/* B7290 80120B90 D7B80030 */  ldc1      $f24, 0x30($sp)
/* B7294 80120B94 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B7298 80120B98 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B729C 80120B9C 03E00008 */  jr        $ra
/* B72A0 80120BA0 27BD0038 */   addiu    $sp, $sp, 0x38
/* B72A4 80120BA4 00000000 */  nop
/* B72A8 80120BA8 00000000 */  nop
/* B72AC 80120BAC 00000000 */  nop
