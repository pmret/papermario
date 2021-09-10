.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80150588
.word L801260B0_BC7B0, L80126080_BC780, L80126260_BC960, L80126074_BC774, L80126074_BC774, L80126074_BC774, L80126074_BC774, L80126294_BC994, L80126294_BC994, L80126294_BC994, L801262E8_BC9E8, L80126080_BC780, L801260F4_BC7F4, L8012612C_BC82C, L801262A0_BC9A0, L80126158_BC858

glabel jtbl_801505C8
.word L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L80126124_BC824, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L80126260_BC960, L801262E8_BC9E8, L801262E8_BC9E8, 0

glabel jtbl_801505F8
.word L80126184_BC884, L801261D8_BC8D8, L801261D8_BC8D8, L801262E8_BC9E8, L801261C4_BC8C4, L80126260_BC960, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L80126260_BC960, L80126260_BC960, L801261E0_BC8E0, L80126224_BC924, L801261A4_BC8A4, L801261A4_BC8A4, L80126260_BC960, L80126260_BC960, L80126260_BC960, L80126260_BC960, L80126260_BC960, L801261A0_BC8A0, L80126260_BC960, L8012619C_BC89C, L80126260_BC960, L801261A0_BC8A0, L801261A4_BC8A4, L80126260_BC960, L801261D8_BC8D8, L80126260_BC960, L80126260_BC960, L80126260_BC960, L80126260_BC960, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L80126234_BC934, L80126260_BC960, L80126268_BC968, L801261AC_BC8AC, L80126260_BC960, L801262E8_BC9E8, L80126198_BC898, L801261D8_BC8D8, L801261D8_BC8D8, L80126260_BC960

glabel jtbl_801506B8
.word L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L80126260_BC960, L801262E8_BC9E8, L80126260_BC960, L801262E8_BC9E8, L80126260_BC960, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, L801262E8_BC9E8, 0

.section .text

glabel get_msg_properties
/* BC668 80125F68 27BDFEB0 */  addiu     $sp, $sp, -0x150
/* BC66C 80125F6C F7B40148 */  sdc1      $f20, 0x148($sp)
/* BC670 80125F70 3C013F80 */  lui       $at, 0x3f80
/* BC674 80125F74 4481A000 */  mtc1      $at, $f20
/* BC678 80125F78 AFB3012C */  sw        $s3, 0x12c($sp)
/* BC67C 80125F7C 97B3016E */  lhu       $s3, 0x16e($sp)
/* BC680 80125F80 AFB00120 */  sw        $s0, 0x120($sp)
/* BC684 80125F84 0080802D */  daddu     $s0, $a0, $zero
/* BC688 80125F88 AFB20128 */  sw        $s2, 0x128($sp)
/* BC68C 80125F8C 0000902D */  daddu     $s2, $zero, $zero
/* BC690 80125F90 AFB7013C */  sw        $s7, 0x13c($sp)
/* BC694 80125F94 0240B82D */  daddu     $s7, $s2, $zero
/* BC698 80125F98 AFBF0144 */  sw        $ra, 0x144($sp)
/* BC69C 80125F9C AFBE0140 */  sw        $fp, 0x140($sp)
/* BC6A0 80125FA0 AFB60138 */  sw        $s6, 0x138($sp)
/* BC6A4 80125FA4 AFB50134 */  sw        $s5, 0x134($sp)
/* BC6A8 80125FA8 AFB40130 */  sw        $s4, 0x130($sp)
/* BC6AC 80125FAC AFB10124 */  sw        $s1, 0x124($sp)
/* BC6B0 80125FB0 AFA50154 */  sw        $a1, 0x154($sp)
/* BC6B4 80125FB4 AFA60158 */  sw        $a2, 0x158($sp)
/* BC6B8 80125FB8 AFA7015C */  sw        $a3, 0x15c($sp)
/* BC6BC 80125FBC A7A000E6 */  sh        $zero, 0xe6($sp)
/* BC6C0 80125FC0 A7A000EE */  sh        $zero, 0xee($sp)
/* BC6C4 80125FC4 AFA000F0 */  sw        $zero, 0xf0($sp)
/* BC6C8 80125FC8 A7A000FE */  sh        $zero, 0xfe($sp)
/* BC6CC 80125FCC A7A00106 */  sh        $zero, 0x106($sp)
/* BC6D0 80125FD0 A7A00108 */  sh        $zero, 0x108($sp)
/* BC6D4 80125FD4 1200011A */  beqz      $s0, .L80126440
/* BC6D8 80125FD8 A7A00116 */   sh       $zero, 0x116($sp)
/* BC6DC 80125FDC 0600000A */  bltz      $s0, .L80126008
/* BC6E0 80125FE0 0200882D */   daddu    $s1, $s0, $zero
/* BC6E4 80125FE4 0C00AB0A */  jal       general_heap_malloc
/* BC6E8 80125FE8 24040400 */   addiu    $a0, $zero, 0x400
/* BC6EC 80125FEC 0200202D */  daddu     $a0, $s0, $zero
/* BC6F0 80125FF0 AFA200F0 */  sw        $v0, 0xf0($sp)
/* BC6F4 80125FF4 0C049601 */  jal       dma_load_msg
/* BC6F8 80125FF8 0040282D */   daddu    $a1, $v0, $zero
/* BC6FC 80125FFC 8FB100F0 */  lw        $s1, 0xf0($sp)
/* BC700 80126000 08049803 */  j         .L8012600C
/* BC704 80126004 32620001 */   andi     $v0, $s3, 1
.L80126008:
/* BC708 80126008 32620001 */  andi      $v0, $s3, 1
.L8012600C:
/* BC70C 8012600C 10400002 */  beqz      $v0, .L80126018
/* BC710 80126010 24080001 */   addiu    $t0, $zero, 1
/* BC714 80126014 A7A800EE */  sh        $t0, 0xee($sp)
.L80126018:
/* BC718 80126018 0000802D */  daddu     $s0, $zero, $zero
/* BC71C 8012601C 0200A02D */  daddu     $s4, $s0, $zero
/* BC720 80126020 0200982D */  daddu     $s3, $s0, $zero
/* BC724 80126024 0200B02D */  daddu     $s6, $s0, $zero
/* BC728 80126028 0200A82D */  daddu     $s5, $s0, $zero
/* BC72C 8012602C 241E0001 */  addiu     $fp, $zero, 1
/* BC730 80126030 27A90018 */  addiu     $t1, $sp, 0x18
/* BC734 80126034 27A80058 */  addiu     $t0, $sp, 0x58
/* BC738 80126038 AFA000D8 */  sw        $zero, 0xd8($sp)
/* BC73C 8012603C AFA9011C */  sw        $t1, 0x11c($sp)
/* BC740 80126040 AFA80118 */  sw        $t0, 0x118($sp)
/* BC744 80126044 02301021 */  addu      $v0, $s1, $s0
.L80126048:
/* BC748 80126048 90440000 */  lbu       $a0, ($v0)
/* BC74C 8012604C 2483FF10 */  addiu     $v1, $a0, -0xf0
/* BC750 80126050 2C620010 */  sltiu     $v0, $v1, 0x10
/* BC754 80126054 10400092 */  beqz      $v0, L801262A0_BC9A0
/* BC758 80126058 26100001 */   addiu    $s0, $s0, 1
/* BC75C 8012605C 00031080 */  sll       $v0, $v1, 2
/* BC760 80126060 3C018015 */  lui       $at, %hi(jtbl_80150588)
/* BC764 80126064 00220821 */  addu      $at, $at, $v0
/* BC768 80126068 8C220588 */  lw        $v0, %lo(jtbl_80150588)($at)
/* BC76C 8012606C 00400008 */  jr        $v0
/* BC770 80126070 00000000 */   nop
glabel L80126074_BC774
/* BC774 80126074 2484FF0D */  addiu     $a0, $a0, -0xf3
/* BC778 80126078 080498BA */  j         L801262E8_BC9E8
/* BC77C 8012607C A7A400E6 */   sh       $a0, 0xe6($sp)
glabel L80126080_BC780
/* BC780 80126080 12C00099 */  beqz      $s6, L801262E8_BC9E8
/* BC784 80126084 32E2FFFF */   andi     $v0, $s7, 0xffff
/* BC788 80126088 00021040 */  sll       $v0, $v0, 1
/* BC78C 8012608C 03A21021 */  addu      $v0, $sp, $v0
/* BC790 80126090 A4560098 */  sh        $s6, 0x98($v0)
/* BC794 80126094 26F70001 */  addiu     $s7, $s7, 1
/* BC798 80126098 32E2FFFF */  andi      $v0, $s7, 0xffff
/* BC79C 8012609C 2C420020 */  sltiu     $v0, $v0, 0x20
/* BC7A0 801260A0 50400001 */  beql      $v0, $zero, .L801260A8
/* BC7A4 801260A4 24140001 */   addiu    $s4, $zero, 1
.L801260A8:
/* BC7A8 801260A8 080498BA */  j         L801262E8_BC9E8
/* BC7AC 801260AC 0000B02D */   daddu    $s6, $zero, $zero
glabel L801260B0_BC7B0
/* BC7B0 801260B0 3243FFFF */  andi      $v1, $s2, 0xffff
/* BC7B4 801260B4 26520001 */  addiu     $s2, $s2, 1
/* BC7B8 801260B8 8FA9011C */  lw        $t1, 0x11c($sp)
/* BC7BC 801260BC 00031840 */  sll       $v1, $v1, 1
/* BC7C0 801260C0 01231021 */  addu      $v0, $t1, $v1
/* BC7C4 801260C4 A4530000 */  sh        $s3, ($v0)
/* BC7C8 801260C8 3242FFFF */  andi      $v0, $s2, 0xffff
/* BC7CC 801260CC 8FA80118 */  lw        $t0, 0x118($sp)
/* BC7D0 801260D0 2C420020 */  sltiu     $v0, $v0, 0x20
/* BC7D4 801260D4 01031821 */  addu      $v1, $t0, $v1
/* BC7D8 801260D8 14400002 */  bnez      $v0, .L801260E4
/* BC7DC 801260DC A4750000 */   sh       $s5, ($v1)
/* BC7E0 801260E0 24140001 */  addiu     $s4, $zero, 1
.L801260E4:
/* BC7E4 801260E4 0000982D */  daddu     $s3, $zero, $zero
/* BC7E8 801260E8 0260A82D */  daddu     $s5, $s3, $zero
/* BC7EC 801260EC 080498BA */  j         L801262E8_BC9E8
/* BC7F0 801260F0 241E0001 */   addiu    $fp, $zero, 1
glabel L801260F4_BC7F4
/* BC7F4 801260F4 02301021 */  addu      $v0, $s1, $s0
/* BC7F8 801260F8 90420000 */  lbu       $v0, ($v0)
/* BC7FC 801260FC 2443FFFF */  addiu     $v1, $v0, -1
/* BC800 80126100 2C62000B */  sltiu     $v0, $v1, 0xb
/* BC804 80126104 10400078 */  beqz      $v0, L801262E8_BC9E8
/* BC808 80126108 26100001 */   addiu    $s0, $s0, 1
/* BC80C 8012610C 00031080 */  sll       $v0, $v1, 2
/* BC810 80126110 3C018015 */  lui       $at, %hi(jtbl_801505C8)
/* BC814 80126114 00220821 */  addu      $at, $at, $v0
/* BC818 80126118 8C2205C8 */  lw        $v0, %lo(jtbl_801505C8)($at)
/* BC81C 8012611C 00400008 */  jr        $v0
/* BC820 80126120 00000000 */   nop
glabel L80126124_BC824
/* BC824 80126124 080498BA */  j         L801262E8_BC9E8
/* BC828 80126128 26100004 */   addiu    $s0, $s0, 4
glabel L8012612C_BC82C
/* BC82C 8012612C 3243FFFF */  andi      $v1, $s2, 0xffff
/* BC830 80126130 26520001 */  addiu     $s2, $s2, 1
/* BC834 80126134 8FA9011C */  lw        $t1, 0x11c($sp)
/* BC838 80126138 00031840 */  sll       $v1, $v1, 1
/* BC83C 8012613C 01231021 */  addu      $v0, $t1, $v1
/* BC840 80126140 A4530000 */  sh        $s3, ($v0)
/* BC844 80126144 8FA80118 */  lw        $t0, 0x118($sp)
/* BC848 80126148 24140001 */  addiu     $s4, $zero, 1
/* BC84C 8012614C 01031821 */  addu      $v1, $t0, $v1
/* BC850 80126150 080498BA */  j         L801262E8_BC9E8
/* BC854 80126154 A4750000 */   sh       $s5, ($v1)
glabel L80126158_BC858
/* BC858 80126158 02301021 */  addu      $v0, $s1, $s0
/* BC85C 8012615C 90430000 */  lbu       $v1, ($v0)
/* BC860 80126160 2C620030 */  sltiu     $v0, $v1, 0x30
/* BC864 80126164 1040001C */  beqz      $v0, L801261D8_BC8D8
/* BC868 80126168 26100001 */   addiu    $s0, $s0, 1
/* BC86C 8012616C 00031080 */  sll       $v0, $v1, 2
/* BC870 80126170 3C018015 */  lui       $at, %hi(jtbl_801505F8)
/* BC874 80126174 00220821 */  addu      $at, $at, $v0
/* BC878 80126178 8C2205F8 */  lw        $v0, %lo(jtbl_801505F8)($at)
/* BC87C 8012617C 00400008 */  jr        $v0
/* BC880 80126180 00000000 */   nop
glabel L80126184_BC884
/* BC884 80126184 02301021 */  addu      $v0, $s1, $s0
/* BC888 80126188 90420000 */  lbu       $v0, ($v0)
/* BC88C 8012618C 26100001 */  addiu     $s0, $s0, 1
/* BC890 80126190 080498BA */  j         L801262E8_BC9E8
/* BC894 80126194 A7A200EE */   sh       $v0, 0xee($sp)
glabel L80126198_BC898
/* BC898 80126198 26100001 */  addiu     $s0, $s0, 1
glabel L8012619C_BC89C
/* BC89C 8012619C 26100004 */  addiu     $s0, $s0, 4
glabel L801261A0_BC8A0
/* BC8A0 801261A0 26100001 */  addiu     $s0, $s0, 1
glabel L801261A4_BC8A4
/* BC8A4 801261A4 08049898 */  j         L80126260_BC960
/* BC8A8 801261A8 26100001 */   addiu    $s0, $s0, 1
glabel L801261AC_BC8AC
/* BC8AC 801261AC 02301021 */  addu      $v0, $s1, $s0
/* BC8B0 801261B0 90420000 */  lbu       $v0, ($v0)
/* BC8B4 801261B4 5040002A */  beql      $v0, $zero, L80126260_BC960
/* BC8B8 801261B8 24140001 */   addiu    $s4, $zero, 1
/* BC8BC 801261BC 080498BA */  j         L801262E8_BC9E8
/* BC8C0 801261C0 26100001 */   addiu    $s0, $s0, 1
glabel L801261C4_BC8C4
/* BC8C4 801261C4 02301021 */  addu      $v0, $s1, $s0
/* BC8C8 801261C8 90430000 */  lbu       $v1, ($v0)
/* BC8CC 801261CC 240200FD */  addiu     $v0, $zero, 0xfd
/* BC8D0 801261D0 14620046 */  bne       $v1, $v0, .L801262EC
/* BC8D4 801261D4 328200FF */   andi     $v0, $s4, 0xff
glabel L801261D8_BC8D8
/* BC8D8 801261D8 080498BA */  j         L801262E8_BC9E8
/* BC8DC 801261DC 24140001 */   addiu    $s4, $zero, 1
glabel L801261E0_BC8E0
/* BC8E0 801261E0 02111021 */  addu      $v0, $s0, $s1
/* BC8E4 801261E4 90420001 */  lbu       $v0, 1($v0)
/* BC8E8 801261E8 3C013D80 */  lui       $at, 0x3d80
/* BC8EC 801261EC 44810000 */  mtc1      $at, $f0
/* BC8F0 801261F0 3043000F */  andi      $v1, $v0, 0xf
/* BC8F4 801261F4 44831000 */  mtc1      $v1, $f2
/* BC8F8 801261F8 00000000 */  nop
/* BC8FC 801261FC 468010A0 */  cvt.s.w   $f2, $f2
/* BC900 80126200 46001082 */  mul.s     $f2, $f2, $f0
/* BC904 80126204 00000000 */  nop
/* BC908 80126208 26100002 */  addiu     $s0, $s0, 2
/* BC90C 8012620C 00021102 */  srl       $v0, $v0, 4
/* BC910 80126210 44820000 */  mtc1      $v0, $f0
/* BC914 80126214 00000000 */  nop
/* BC918 80126218 46800020 */  cvt.s.w   $f0, $f0
/* BC91C 8012621C 080498BA */  j         L801262E8_BC9E8
/* BC920 80126220 46020500 */   add.s    $f20, $f0, $f2
glabel L80126224_BC924
/* BC924 80126224 3C013F80 */  lui       $at, 0x3f80
/* BC928 80126228 4481A000 */  mtc1      $at, $f20
/* BC92C 8012622C 080498BB */  j         .L801262EC
/* BC930 80126230 328200FF */   andi     $v0, $s4, 0xff
glabel L80126234_BC934
/* BC934 80126234 02301021 */  addu      $v0, $s1, $s0
/* BC938 80126238 90430000 */  lbu       $v1, ($v0)
/* BC93C 8012623C 2C62000F */  sltiu     $v0, $v1, 0xf
/* BC940 80126240 10400029 */  beqz      $v0, L801262E8_BC9E8
/* BC944 80126244 26100001 */   addiu    $s0, $s0, 1
/* BC948 80126248 00031080 */  sll       $v0, $v1, 2
/* BC94C 8012624C 3C018015 */  lui       $at, %hi(jtbl_801506B8)
/* BC950 80126250 00220821 */  addu      $at, $at, $v0
/* BC954 80126254 8C2206B8 */  lw        $v0, %lo(jtbl_801506B8)($at)
/* BC958 80126258 00400008 */  jr        $v0
/* BC95C 8012625C 00000000 */   nop
glabel L80126260_BC960
/* BC960 80126260 080498BA */  j         L801262E8_BC9E8
/* BC964 80126264 26100001 */   addiu    $s0, $s0, 1
glabel L80126268_BC968
/* BC968 80126268 02301021 */  addu      $v0, $s1, $s0
/* BC96C 8012626C 26100001 */  addiu     $s0, $s0, 1
/* BC970 80126270 90440000 */  lbu       $a0, ($v0)
/* BC974 80126274 0000282D */  daddu     $a1, $zero, $zero
/* BC978 80126278 3C098015 */  lui       $t1, %hi(gMessageMsgVars)
/* BC97C 8012627C 25295C38 */  addiu     $t1, $t1, %lo(gMessageMsgVars)
/* BC980 80126280 00042140 */  sll       $a0, $a0, 5
/* BC984 80126284 0C04991D */  jal       get_msg_width
/* BC988 80126288 00892021 */   addu     $a0, $a0, $t1
/* BC98C 8012628C 080498BA */  j         L801262E8_BC9E8
/* BC990 80126290 02629821 */   addu     $s3, $s3, $v0
glabel L80126294_BC994
/* BC994 80126294 97A80116 */  lhu       $t0, 0x116($sp)
/* BC998 80126298 25080001 */  addiu     $t0, $t0, 1
/* BC99C 8012629C A7A80116 */  sh        $t0, 0x116($sp)
glabel L801262A0_BC9A0
/* BC9A0 801262A0 33C2FFFF */  andi      $v0, $fp, 0xffff
/* BC9A4 801262A4 10400006 */  beqz      $v0, .L801262C0
/* BC9A8 801262A8 308400FF */   andi     $a0, $a0, 0xff
/* BC9AC 801262AC 8FA900D8 */  lw        $t1, 0xd8($sp)
/* BC9B0 801262B0 25290001 */  addiu     $t1, $t1, 1
/* BC9B4 801262B4 AFA900D8 */  sw        $t1, 0xd8($sp)
/* BC9B8 801262B8 26D60001 */  addiu     $s6, $s6, 1
/* BC9BC 801262BC 0000F02D */  daddu     $fp, $zero, $zero
.L801262C0:
/* BC9C0 801262C0 26B50001 */  addiu     $s5, $s5, 1
/* BC9C4 801262C4 97A800EE */  lhu       $t0, 0xee($sp)
/* BC9C8 801262C8 4407A000 */  mfc1      $a3, $f20
/* BC9CC 801262CC 97A600E6 */  lhu       $a2, 0xe6($sp)
/* BC9D0 801262D0 24020001 */  addiu     $v0, $zero, 1
/* BC9D4 801262D4 AFA00010 */  sw        $zero, 0x10($sp)
/* BC9D8 801262D8 AFA20014 */  sw        $v0, 0x14($sp)
/* BC9DC 801262DC 0C049721 */  jal       msg_get_print_char_width
/* BC9E0 801262E0 0100282D */   daddu    $a1, $t0, $zero
/* BC9E4 801262E4 02629821 */  addu      $s3, $s3, $v0
glabel L801262E8_BC9E8
/* BC9E8 801262E8 328200FF */  andi      $v0, $s4, 0xff
.L801262EC:
/* BC9EC 801262EC 1040FF56 */  beqz      $v0, .L80126048
/* BC9F0 801262F0 02301021 */   addu     $v0, $s1, $s0
/* BC9F4 801262F4 8FA900F0 */  lw        $t1, 0xf0($sp)
/* BC9F8 801262F8 11200004 */  beqz      $t1, .L8012630C
/* BC9FC 801262FC 3242FFFF */   andi     $v0, $s2, 0xffff
/* BCA00 80126300 0C00AB1E */  jal       general_heap_free
/* BCA04 80126304 0120202D */   daddu    $a0, $t1, $zero
/* BCA08 80126308 3242FFFF */  andi      $v0, $s2, 0xffff
.L8012630C:
/* BCA0C 8012630C 10400013 */  beqz      $v0, .L8012635C
/* BCA10 80126310 0000802D */   daddu    $s0, $zero, $zero
/* BCA14 80126314 0040182D */  daddu     $v1, $v0, $zero
/* BCA18 80126318 27A60058 */  addiu     $a2, $sp, 0x58
/* BCA1C 8012631C 27A50018 */  addiu     $a1, $sp, 0x18
.L80126320:
/* BCA20 80126320 94A40000 */  lhu       $a0, ($a1)
/* BCA24 80126324 97A800FE */  lhu       $t0, 0xfe($sp)
/* BCA28 80126328 0104102B */  sltu      $v0, $t0, $a0
/* BCA2C 8012632C 54400001 */  bnel      $v0, $zero, .L80126334
/* BCA30 80126330 A7A400FE */   sh       $a0, 0xfe($sp)
.L80126334:
/* BCA34 80126334 94C40000 */  lhu       $a0, ($a2)
/* BCA38 80126338 97A90106 */  lhu       $t1, 0x106($sp)
/* BCA3C 8012633C 0124102B */  sltu      $v0, $t1, $a0
/* BCA40 80126340 54400001 */  bnel      $v0, $zero, .L80126348
/* BCA44 80126344 A7A40106 */   sh       $a0, 0x106($sp)
.L80126348:
/* BCA48 80126348 24C60002 */  addiu     $a2, $a2, 2
/* BCA4C 8012634C 26100001 */  addiu     $s0, $s0, 1
/* BCA50 80126350 0203102A */  slt       $v0, $s0, $v1
/* BCA54 80126354 1440FFF2 */  bnez      $v0, .L80126320
/* BCA58 80126358 24A50002 */   addiu    $a1, $a1, 2
.L8012635C:
/* BCA5C 8012635C 32E2FFFF */  andi      $v0, $s7, 0xffff
/* BCA60 80126360 14400003 */  bnez      $v0, .L80126370
/* BCA64 80126364 00000000 */   nop
/* BCA68 80126368 080498E9 */  j         .L801263A4
/* BCA6C 8012636C A7B60108 */   sh       $s6, 0x108($sp)
.L80126370:
/* BCA70 80126370 1040000C */  beqz      $v0, .L801263A4
/* BCA74 80126374 0000802D */   daddu    $s0, $zero, $zero
/* BCA78 80126378 0040282D */  daddu     $a1, $v0, $zero
/* BCA7C 8012637C 27A40098 */  addiu     $a0, $sp, 0x98
.L80126380:
/* BCA80 80126380 94830000 */  lhu       $v1, ($a0)
/* BCA84 80126384 97A20108 */  lhu       $v0, 0x108($sp)
/* BCA88 80126388 0043102B */  sltu      $v0, $v0, $v1
/* BCA8C 8012638C 54400001 */  bnel      $v0, $zero, .L80126394
/* BCA90 80126390 A7A30108 */   sh       $v1, 0x108($sp)
.L80126394:
/* BCA94 80126394 26100001 */  addiu     $s0, $s0, 1
/* BCA98 80126398 0205102A */  slt       $v0, $s0, $a1
/* BCA9C 8012639C 1440FFF8 */  bnez      $v0, .L80126380
/* BCAA0 801263A0 24840002 */   addiu    $a0, $a0, 2
.L801263A4:
/* BCAA4 801263A4 8FA80158 */  lw        $t0, 0x158($sp)
/* BCAA8 801263A8 11000003 */  beqz      $t0, .L801263B8
/* BCAAC 801263AC 00000000 */   nop
/* BCAB0 801263B0 97A900FE */  lhu       $t1, 0xfe($sp)
/* BCAB4 801263B4 AD090000 */  sw        $t1, ($t0)
.L801263B8:
/* BCAB8 801263B8 8FA80154 */  lw        $t0, 0x154($sp)
/* BCABC 801263BC 1100000C */  beqz      $t0, .L801263F0
/* BCAC0 801263C0 00000000 */   nop
/* BCAC4 801263C4 97A900EE */  lhu       $t1, 0xee($sp)
/* BCAC8 801263C8 00091080 */  sll       $v0, $t1, 2
/* BCACC 801263CC 3C01802F */  lui       $at, %hi(gMsgCharsets)
/* BCAD0 801263D0 00220821 */  addu      $at, $at, $v0
/* BCAD4 801263D4 8C22B5A8 */  lw        $v0, %lo(gMsgCharsets)($at)
/* BCAD8 801263D8 8FA800D8 */  lw        $t0, 0xd8($sp)
/* BCADC 801263DC 90420003 */  lbu       $v0, 3($v0)
/* BCAE0 801263E0 01020018 */  mult      $t0, $v0
/* BCAE4 801263E4 8FA90154 */  lw        $t1, 0x154($sp)
/* BCAE8 801263E8 00004012 */  mflo      $t0
/* BCAEC 801263EC AD280000 */  sw        $t0, ($t1)
.L801263F0:
/* BCAF0 801263F0 8FA9015C */  lw        $t1, 0x15c($sp)
/* BCAF4 801263F4 11200003 */  beqz      $t1, .L80126404
/* BCAF8 801263F8 00000000 */   nop
/* BCAFC 801263FC 97A80106 */  lhu       $t0, 0x106($sp)
/* BCB00 80126400 AD280000 */  sw        $t0, ($t1)
.L80126404:
/* BCB04 80126404 8FA90160 */  lw        $t1, 0x160($sp)
/* BCB08 80126408 11200003 */  beqz      $t1, .L80126418
/* BCB0C 8012640C 00000000 */   nop
/* BCB10 80126410 8FA800D8 */  lw        $t0, 0xd8($sp)
/* BCB14 80126414 AD280000 */  sw        $t0, ($t1)
.L80126418:
/* BCB18 80126418 8FA90164 */  lw        $t1, 0x164($sp)
/* BCB1C 8012641C 11200003 */  beqz      $t1, .L8012642C
/* BCB20 80126420 00000000 */   nop
/* BCB24 80126424 97A20108 */  lhu       $v0, 0x108($sp)
/* BCB28 80126428 AD220000 */  sw        $v0, ($t1)
.L8012642C:
/* BCB2C 8012642C 8FA80168 */  lw        $t0, 0x168($sp)
/* BCB30 80126430 11000003 */  beqz      $t0, .L80126440
/* BCB34 80126434 00000000 */   nop
/* BCB38 80126438 97A20116 */  lhu       $v0, 0x116($sp)
/* BCB3C 8012643C AD020000 */  sw        $v0, ($t0)
.L80126440:
/* BCB40 80126440 8FBF0144 */  lw        $ra, 0x144($sp)
/* BCB44 80126444 8FBE0140 */  lw        $fp, 0x140($sp)
/* BCB48 80126448 8FB7013C */  lw        $s7, 0x13c($sp)
/* BCB4C 8012644C 8FB60138 */  lw        $s6, 0x138($sp)
/* BCB50 80126450 8FB50134 */  lw        $s5, 0x134($sp)
/* BCB54 80126454 8FB40130 */  lw        $s4, 0x130($sp)
/* BCB58 80126458 8FB3012C */  lw        $s3, 0x12c($sp)
/* BCB5C 8012645C 8FB20128 */  lw        $s2, 0x128($sp)
/* BCB60 80126460 8FB10124 */  lw        $s1, 0x124($sp)
/* BCB64 80126464 8FB00120 */  lw        $s0, 0x120($sp)
/* BCB68 80126468 D7B40148 */  ldc1      $f20, 0x148($sp)
/* BCB6C 8012646C 03E00008 */  jr        $ra
/* BCB70 80126470 27BD0150 */   addiu    $sp, $sp, 0x150
