.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00CE478
/* 3D2F38 E00CE478 27BDFEE0 */  addiu     $sp, $sp, -0x120
/* 3D2F3C E00CE47C 0080502D */  daddu     $t2, $a0, $zero
/* 3D2F40 E00CE480 3C0BDB06 */  lui       $t3, 0xdb06
/* 3D2F44 E00CE484 356B0024 */  ori       $t3, $t3, 0x24
/* 3D2F48 E00CE488 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D2F4C E00CE48C AFB300D4 */  sw        $s3, 0xd4($sp)
/* 3D2F50 E00CE490 3C130001 */  lui       $s3, 1
/* 3D2F54 E00CE494 36731630 */  ori       $s3, $s3, 0x1630
/* 3D2F58 E00CE498 AFB400D8 */  sw        $s4, 0xd8($sp)
/* 3D2F5C E00CE49C 0000A02D */  daddu     $s4, $zero, $zero
/* 3D2F60 E00CE4A0 AFBE00E8 */  sw        $fp, 0xe8($sp)
/* 3D2F64 E00CE4A4 241E0400 */  addiu     $fp, $zero, 0x400
/* 3D2F68 E00CE4A8 AFB700E4 */  sw        $s7, 0xe4($sp)
/* 3D2F6C E00CE4AC 24170100 */  addiu     $s7, $zero, 0x100
/* 3D2F70 E00CE4B0 AFB500DC */  sw        $s5, 0xdc($sp)
/* 3D2F74 E00CE4B4 0280A82D */  daddu     $s5, $s4, $zero
/* 3D2F78 E00CE4B8 AFB100CC */  sw        $s1, 0xcc($sp)
/* 3D2F7C E00CE4BC 3C11800A */  lui       $s1, %hi(D_8009A66C)
/* 3D2F80 E00CE4C0 2631A66C */  addiu     $s1, $s1, %lo(D_8009A66C)
/* 3D2F84 E00CE4C4 AFBF00EC */  sw        $ra, 0xec($sp)
/* 3D2F88 E00CE4C8 AFB600E0 */  sw        $s6, 0xe0($sp)
/* 3D2F8C E00CE4CC AFB200D0 */  sw        $s2, 0xd0($sp)
/* 3D2F90 E00CE4D0 AFB000C8 */  sw        $s0, 0xc8($sp)
/* 3D2F94 E00CE4D4 F7BE0118 */  sdc1      $f30, 0x118($sp)
/* 3D2F98 E00CE4D8 F7BC0110 */  sdc1      $f28, 0x110($sp)
/* 3D2F9C E00CE4DC F7BA0108 */  sdc1      $f26, 0x108($sp)
/* 3D2FA0 E00CE4E0 F7B80100 */  sdc1      $f24, 0x100($sp)
/* 3D2FA4 E00CE4E4 F7B600F8 */  sdc1      $f22, 0xf8($sp)
/* 3D2FA8 E00CE4E8 F7B400F0 */  sdc1      $f20, 0xf0($sp)
/* 3D2FAC E00CE4EC 8E230000 */  lw        $v1, ($s1)
/* 3D2FB0 E00CE4F0 44800000 */  mtc1      $zero, $f0
/* 3D2FB4 E00CE4F4 3C0142C8 */  lui       $at, 0x42c8
/* 3D2FB8 E00CE4F8 4481B000 */  mtc1      $at, $f22
/* 3D2FBC E00CE4FC 8D56000C */  lw        $s6, 0xc($t2)
/* 3D2FC0 E00CE500 3C014080 */  lui       $at, 0x4080
/* 3D2FC4 E00CE504 44812000 */  mtc1      $at, $f4
/* 3D2FC8 E00CE508 0060402D */  daddu     $t0, $v1, $zero
/* 3D2FCC E00CE50C 44050000 */  mfc1      $a1, $f0
/* 3D2FD0 E00CE510 24630008 */  addiu     $v1, $v1, 8
/* 3D2FD4 E00CE514 AE230000 */  sw        $v1, ($s1)
/* 3D2FD8 E00CE518 8ECC0010 */  lw        $t4, 0x10($s6)
/* 3D2FDC E00CE51C 3C02E700 */  lui       $v0, 0xe700
/* 3D2FE0 E00CE520 AFAC00A0 */  sw        $t4, 0xa0($sp)
/* 3D2FE4 E00CE524 8EC90024 */  lw        $t1, 0x24($s6)
/* 3D2FE8 E00CE528 C6C60034 */  lwc1      $f6, 0x34($s6)
/* 3D2FEC E00CE52C 00A0302D */  daddu     $a2, $a1, $zero
/* 3D2FF0 E00CE530 E7A600B8 */  swc1      $f6, 0xb8($sp)
/* 3D2FF4 E00CE534 C6C0013C */  lwc1      $f0, 0x13c($s6)
/* 3D2FF8 E00CE538 C6C20140 */  lwc1      $f2, 0x140($s6)
/* 3D2FFC E00CE53C AD020000 */  sw        $v0, ($t0)
/* 3D3000 E00CE540 24620008 */  addiu     $v0, $v1, 8
/* 3D3004 E00CE544 AD000004 */  sw        $zero, 4($t0)
/* 3D3008 E00CE548 3C088000 */  lui       $t0, 0x8000
/* 3D300C E00CE54C AE220000 */  sw        $v0, ($s1)
/* 3D3010 E00CE550 46040002 */  mul.s     $f0, $f0, $f4
/* 3D3014 E00CE554 00000000 */  nop       
/* 3D3018 E00CE558 AC6B0000 */  sw        $t3, ($v1)
/* 3D301C E00CE55C 8D420010 */  lw        $v0, 0x10($t2)
/* 3D3020 E00CE560 00094843 */  sra       $t1, $t1, 1
/* 3D3024 E00CE564 8C42001C */  lw        $v0, 0x1c($v0)
/* 3D3028 E00CE568 46041082 */  mul.s     $f2, $f2, $f4
/* 3D302C E00CE56C 00000000 */  nop       
/* 3D3030 E00CE570 00481021 */  addu      $v0, $v0, $t0
/* 3D3034 E00CE574 AC620004 */  sw        $v0, 4($v1)
/* 3D3038 E00CE578 AFA900A4 */  sw        $t1, 0xa4($sp)
/* 3D303C E00CE57C 4600018D */  trunc.w.s $f6, $f0
/* 3D3040 E00CE580 E7A600B0 */  swc1      $f6, 0xb0($sp)
/* 3D3044 E00CE584 4600118D */  trunc.w.s $f6, $f2
/* 3D3048 E00CE588 E7A600B4 */  swc1      $f6, 0xb4($sp)
/* 3D304C E00CE58C 0C080108 */  jal       func_E0200420
/* 3D3050 E00CE590 00A0382D */   daddu    $a3, $a1, $zero
/* 3D3054 E00CE594 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D3058 E00CE598 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 3D305C E00CE59C 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 3D3060 E00CE5A0 3C12800A */  lui       $s2, %hi(D_8009A674)
/* 3D3064 E00CE5A4 2652A674 */  addiu     $s2, $s2, %lo(D_8009A674)
/* 3D3068 E00CE5A8 96050000 */  lhu       $a1, ($s0)
/* 3D306C E00CE5AC 8E420000 */  lw        $v0, ($s2)
/* 3D3070 E00CE5B0 00052980 */  sll       $a1, $a1, 6
/* 3D3074 E00CE5B4 00B32821 */  addu      $a1, $a1, $s3
/* 3D3078 E00CE5B8 0C080118 */  jal       func_E0200460
/* 3D307C E00CE5BC 00452821 */   addu     $a1, $v0, $a1
/* 3D3080 E00CE5C0 3C03DA38 */  lui       $v1, 0xda38
/* 3D3084 E00CE5C4 34630002 */  ori       $v1, $v1, 2
/* 3D3088 E00CE5C8 8E240000 */  lw        $a0, ($s1)
/* 3D308C E00CE5CC 96020000 */  lhu       $v0, ($s0)
/* 3D3090 E00CE5D0 0080282D */  daddu     $a1, $a0, $zero
/* 3D3094 E00CE5D4 24840008 */  addiu     $a0, $a0, 8
/* 3D3098 E00CE5D8 248C0010 */  addiu     $t4, $a0, 0x10
/* 3D309C E00CE5DC AFAC00AC */  sw        $t4, 0xac($sp)
/* 3D30A0 E00CE5E0 AE240000 */  sw        $a0, ($s1)
/* 3D30A4 E00CE5E4 ACA30000 */  sw        $v1, ($a1)
/* 3D30A8 E00CE5E8 24430001 */  addiu     $v1, $v0, 1
/* 3D30AC E00CE5EC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D30B0 E00CE5F0 00021180 */  sll       $v0, $v0, 6
/* 3D30B4 E00CE5F4 A6030000 */  sh        $v1, ($s0)
/* 3D30B8 E00CE5F8 8E430000 */  lw        $v1, ($s2)
/* 3D30BC E00CE5FC 00531021 */  addu      $v0, $v0, $s3
/* 3D30C0 E00CE600 00621821 */  addu      $v1, $v1, $v0
/* 3D30C4 E00CE604 24820008 */  addiu     $v0, $a0, 8
/* 3D30C8 E00CE608 ACA30004 */  sw        $v1, 4($a1)
/* 3D30CC E00CE60C AE220000 */  sw        $v0, ($s1)
/* 3D30D0 E00CE610 3C02DE00 */  lui       $v0, 0xde00
/* 3D30D4 E00CE614 AC820000 */  sw        $v0, ($a0)
/* 3D30D8 E00CE618 3C020900 */  lui       $v0, 0x900
/* 3D30DC E00CE61C 24420400 */  addiu     $v0, $v0, 0x400
/* 3D30E0 E00CE620 AC820004 */  sw        $v0, 4($a0)
/* 3D30E4 E00CE624 3C02DE01 */  lui       $v0, 0xde01
/* 3D30E8 E00CE628 AC820008 */  sw        $v0, 8($a0)
/* 3D30EC E00CE62C 24820210 */  addiu     $v0, $a0, 0x210
/* 3D30F0 E00CE630 AC82000C */  sw        $v0, 0xc($a0)
/* 3D30F4 E00CE634 AE220000 */  sw        $v0, ($s1)
/* 3D30F8 E00CE638 00141100 */  sll       $v0, $s4, 4
.LE00CE63C:
/* 3D30FC E00CE63C 4495A000 */  mtc1      $s5, $f20
/* 3D3100 E00CE640 00000000 */  nop       
/* 3D3104 E00CE644 4680A520 */  cvt.s.w   $f20, $f20
/* 3D3108 E00CE648 8FAC00AC */  lw        $t4, 0xac($sp)
/* 3D310C E00CE64C 4600A306 */  mov.s     $f12, $f20
/* 3D3110 E00CE650 0C080144 */  jal       func_E0200510
/* 3D3114 E00CE654 01828021 */   addu     $s0, $t4, $v0
/* 3D3118 E00CE658 46160002 */  mul.s     $f0, $f0, $f22
/* 3D311C E00CE65C 00000000 */  nop       
/* 3D3120 E00CE660 4600A306 */  mov.s     $f12, $f20
/* 3D3124 E00CE664 26B50018 */  addiu     $s5, $s5, 0x18
/* 3D3128 E00CE668 A6000002 */  sh        $zero, 2($s0)
/* 3D312C E00CE66C 4600018D */  trunc.w.s $f6, $f0
/* 3D3130 E00CE670 44023000 */  mfc1      $v0, $f6
/* 3D3134 E00CE674 0C080140 */  jal       func_E0200500
/* 3D3138 E00CE678 A6020000 */   sh       $v0, ($s0)
/* 3D313C E00CE67C 46160002 */  mul.s     $f0, $f0, $f22
/* 3D3140 E00CE680 00000000 */  nop       
/* 3D3144 E00CE684 4600A306 */  mov.s     $f12, $f20
/* 3D3148 E00CE688 001411C0 */  sll       $v0, $s4, 7
/* 3D314C E00CE68C A6020008 */  sh        $v0, 8($s0)
/* 3D3150 E00CE690 A600000A */  sh        $zero, 0xa($s0)
/* 3D3154 E00CE694 4600018D */  trunc.w.s $f6, $f0
/* 3D3158 E00CE698 44023000 */  mfc1      $v0, $f6
/* 3D315C E00CE69C 0C080144 */  jal       func_E0200510
/* 3D3160 E00CE6A0 A6020004 */   sh       $v0, 4($s0)
/* 3D3164 E00CE6A4 46160002 */  mul.s     $f0, $f0, $f22
/* 3D3168 E00CE6A8 00000000 */  nop       
/* 3D316C E00CE6AC 8FAC00AC */  lw        $t4, 0xac($sp)
/* 3D3170 E00CE6B0 4600A306 */  mov.s     $f12, $f20
/* 3D3174 E00CE6B4 01978021 */  addu      $s0, $t4, $s7
/* 3D3178 E00CE6B8 26F70010 */  addiu     $s7, $s7, 0x10
/* 3D317C E00CE6BC A6000002 */  sh        $zero, 2($s0)
/* 3D3180 E00CE6C0 4600018D */  trunc.w.s $f6, $f0
/* 3D3184 E00CE6C4 44023000 */  mfc1      $v0, $f6
/* 3D3188 E00CE6C8 0C080140 */  jal       func_E0200500
/* 3D318C E00CE6CC A6020000 */   sh       $v0, ($s0)
/* 3D3190 E00CE6D0 46160002 */  mul.s     $f0, $f0, $f22
/* 3D3194 E00CE6D4 00000000 */  nop       
/* 3D3198 E00CE6D8 00141240 */  sll       $v0, $s4, 9
/* 3D319C E00CE6DC 26940001 */  addiu     $s4, $s4, 1
/* 3D31A0 E00CE6E0 A6020008 */  sh        $v0, 8($s0)
/* 3D31A4 E00CE6E4 A61E000A */  sh        $fp, 0xa($s0)
/* 3D31A8 E00CE6E8 4600018D */  trunc.w.s $f6, $f0
/* 3D31AC E00CE6EC 44023000 */  mfc1      $v0, $f6
/* 3D31B0 E00CE6F0 00000000 */  nop       
/* 3D31B4 E00CE6F4 A6020004 */  sh        $v0, 4($s0)
/* 3D31B8 E00CE6F8 2A820010 */  slti      $v0, $s4, 0x10
/* 3D31BC E00CE6FC 1440FFCF */  bnez      $v0, .LE00CE63C
/* 3D31C0 E00CE700 00141100 */   sll      $v0, $s4, 4
/* 3D31C4 E00CE704 3C02800A */  lui       $v0, %hi(D_8009A66C)
/* 3D31C8 E00CE708 2442A66C */  addiu     $v0, $v0, %lo(D_8009A66C)
/* 3D31CC E00CE70C 0040402D */  daddu     $t0, $v0, $zero
/* 3D31D0 E00CE710 8D030000 */  lw        $v1, ($t0)
/* 3D31D4 E00CE714 0000A02D */  daddu     $s4, $zero, $zero
/* 3D31D8 E00CE718 24620008 */  addiu     $v0, $v1, 8
/* 3D31DC E00CE71C AFA200A8 */  sw        $v0, 0xa8($sp)
/* 3D31E0 E00CE720 3C02DE01 */  lui       $v0, 0xde01
/* 3D31E4 E00CE724 AC620000 */  sw        $v0, ($v1)
/* 3D31E8 E00CE728 24620088 */  addiu     $v0, $v1, 0x88
/* 3D31EC E00CE72C AC620004 */  sw        $v0, 4($v1)
/* 3D31F0 E00CE730 8FAC00A8 */  lw        $t4, 0xa8($sp)
/* 3D31F4 E00CE734 3C090600 */  lui       $t1, 0x600
/* 3D31F8 E00CE738 AD0C0000 */  sw        $t4, ($t0)
.LE00CE73C:
/* 3D31FC E00CE73C 26830010 */  addiu     $v1, $s4, 0x10
/* 3D3200 E00CE740 26840001 */  addiu     $a0, $s4, 1
/* 3D3204 E00CE744 00143040 */  sll       $a2, $s4, 1
/* 3D3208 E00CE748 26850011 */  addiu     $a1, $s4, 0x11
/* 3D320C E00CE74C 0080A02D */  daddu     $s4, $a0, $zero
/* 3D3210 E00CE750 00031840 */  sll       $v1, $v1, 1
/* 3D3214 E00CE754 306300FF */  andi      $v1, $v1, 0xff
/* 3D3218 E00CE758 00031C00 */  sll       $v1, $v1, 0x10
/* 3D321C E00CE75C 00142040 */  sll       $a0, $s4, 1
/* 3D3220 E00CE760 308400FF */  andi      $a0, $a0, 0xff
/* 3D3224 E00CE764 30C600FF */  andi      $a2, $a2, 0xff
/* 3D3228 E00CE768 00052A40 */  sll       $a1, $a1, 9
/* 3D322C E00CE76C 8D020000 */  lw        $v0, ($t0)
/* 3D3230 E00CE770 30A5FE00 */  andi      $a1, $a1, 0xfe00
/* 3D3234 E00CE774 0040382D */  daddu     $a3, $v0, $zero
/* 3D3238 E00CE778 24420008 */  addiu     $v0, $v0, 8
/* 3D323C E00CE77C AD020000 */  sw        $v0, ($t0)
/* 3D3240 E00CE780 00041200 */  sll       $v0, $a0, 8
/* 3D3244 E00CE784 00621025 */  or        $v0, $v1, $v0
/* 3D3248 E00CE788 00461025 */  or        $v0, $v0, $a2
/* 3D324C E00CE78C 00491025 */  or        $v0, $v0, $t1
/* 3D3250 E00CE790 00651825 */  or        $v1, $v1, $a1
/* 3D3254 E00CE794 00641825 */  or        $v1, $v1, $a0
/* 3D3258 E00CE798 ACE20000 */  sw        $v0, ($a3)
/* 3D325C E00CE79C 2A82000F */  slti      $v0, $s4, 0xf
/* 3D3260 E00CE7A0 1440FFE6 */  bnez      $v0, .LE00CE73C
/* 3D3264 E00CE7A4 ACE30004 */   sw       $v1, 4($a3)
/* 3D3268 E00CE7A8 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D326C E00CE7AC 3C100001 */  lui       $s0, 1
/* 3D3270 E00CE7B0 36101630 */  ori       $s0, $s0, 0x1630
/* 3D3274 E00CE7B4 0000A02D */  daddu     $s4, $zero, $zero
/* 3D3278 E00CE7B8 27B30060 */  addiu     $s3, $sp, 0x60
/* 3D327C E00CE7BC 3C028007 */  lui       $v0, %hi(D_800741F0)
/* 3D3280 E00CE7C0 244241F0 */  addiu     $v0, $v0, %lo(D_800741F0)
/* 3D3284 E00CE7C4 0040B82D */  daddu     $s7, $v0, $zero
/* 3D3288 E00CE7C8 3C1E0001 */  lui       $fp, 1
/* 3D328C E00CE7CC 3C02800A */  lui       $v0, %hi(D_8009A66C)
/* 3D3290 E00CE7D0 2442A66C */  addiu     $v0, $v0, %lo(D_8009A66C)
/* 3D3294 E00CE7D4 0040A82D */  daddu     $s5, $v0, $zero
/* 3D3298 E00CE7D8 3C0CD838 */  lui       $t4, 0xd838
/* 3D329C E00CE7DC 358C0002 */  ori       $t4, $t4, 2
/* 3D32A0 E00CE7E0 AFAC00C4 */  sw        $t4, 0xc4($sp)
/* 3D32A4 E00CE7E4 8EA20000 */  lw        $v0, ($s5)
/* 3D32A8 E00CE7E8 4480F000 */  mtc1      $zero, $f30
/* 3D32AC E00CE7EC 3C013DCC */  lui       $at, 0x3dcc
/* 3D32B0 E00CE7F0 3421CCCD */  ori       $at, $at, 0xcccd
/* 3D32B4 E00CE7F4 44810000 */  mtc1      $at, $f0
/* 3D32B8 E00CE7F8 0040182D */  daddu     $v1, $v0, $zero
/* 3D32BC E00CE7FC 44050000 */  mfc1      $a1, $f0
/* 3D32C0 E00CE800 24420008 */  addiu     $v0, $v0, 8
/* 3D32C4 E00CE804 AEA20000 */  sw        $v0, ($s5)
/* 3D32C8 E00CE808 3C02DF00 */  lui       $v0, 0xdf00
/* 3D32CC E00CE80C AC620000 */  sw        $v0, ($v1)
/* 3D32D0 E00CE810 AC600004 */  sw        $zero, 4($v1)
/* 3D32D4 E00CE814 00A0302D */  daddu     $a2, $a1, $zero
/* 3D32D8 E00CE818 0C080110 */  jal       func_E0200440
/* 3D32DC E00CE81C 00A0382D */   daddu    $a3, $a1, $zero
/* 3D32E0 E00CE820 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D32E4 E00CE824 96E50000 */  lhu       $a1, ($s7)
/* 3D32E8 E00CE828 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 3D32EC E00CE82C 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 3D32F0 E00CE830 00052980 */  sll       $a1, $a1, 6
/* 3D32F4 E00CE834 00B02821 */  addu      $a1, $a1, $s0
/* 3D32F8 E00CE838 0C080118 */  jal       func_E0200460
/* 3D32FC E00CE83C 00452821 */   addu     $a1, $v0, $a1
/* 3D3300 E00CE840 8EA20000 */  lw        $v0, ($s5)
/* 3D3304 E00CE844 3C014120 */  lui       $at, 0x4120
/* 3D3308 E00CE848 4481D000 */  mtc1      $at, $f26
/* 3D330C E00CE84C 0040202D */  daddu     $a0, $v0, $zero
/* 3D3310 E00CE850 24420008 */  addiu     $v0, $v0, 8
/* 3D3314 E00CE854 AFA200C0 */  sw        $v0, 0xc0($sp)
/* 3D3318 E00CE858 8FAC00C0 */  lw        $t4, 0xc0($sp)
/* 3D331C E00CE85C 24420008 */  addiu     $v0, $v0, 8
/* 3D3320 E00CE860 AFA200BC */  sw        $v0, 0xbc($sp)
/* 3D3324 E00CE864 AEAC0000 */  sw        $t4, ($s5)
/* 3D3328 E00CE868 96E20000 */  lhu       $v0, ($s7)
/* 3D332C E00CE86C 3C03DA38 */  lui       $v1, 0xda38
/* 3D3330 E00CE870 AC830000 */  sw        $v1, ($a0)
/* 3D3334 E00CE874 24430001 */  addiu     $v1, $v0, 1
/* 3D3338 E00CE878 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D333C E00CE87C 00021180 */  sll       $v0, $v0, 6
/* 3D3340 E00CE880 A6E30000 */  sh        $v1, ($s7)
/* 3D3344 E00CE884 3C03800A */  lui       $v1, %hi(D_8009A674)
/* 3D3348 E00CE888 8C63A674 */  lw        $v1, %lo(D_8009A674)($v1)
/* 3D334C E00CE88C 00501021 */  addu      $v0, $v0, $s0
/* 3D3350 E00CE890 00621821 */  addu      $v1, $v1, $v0
/* 3D3354 E00CE894 AC830004 */  sw        $v1, 4($a0)
/* 3D3358 E00CE898 8FAC00BC */  lw        $t4, 0xbc($sp)
/* 3D335C E00CE89C 37DE1630 */  ori       $fp, $fp, 0x1630
/* 3D3360 E00CE8A0 AEAC0000 */  sw        $t4, ($s5)
.LE00CE8A4:
/* 3D3364 E00CE8A4 00141080 */  sll       $v0, $s4, 2
/* 3D3368 E00CE8A8 3C013F80 */  lui       $at, 0x3f80
/* 3D336C E00CE8AC 44813000 */  mtc1      $at, $f6
/* 3D3370 E00CE8B0 02C29021 */  addu      $s2, $s6, $v0
/* 3D3374 E00CE8B4 E7A60010 */  swc1      $f6, 0x10($sp)
/* 3D3378 E00CE8B8 C6400038 */  lwc1      $f0, 0x38($s2)
/* 3D337C E00CE8BC 461A0002 */  mul.s     $f0, $f0, $f26
/* 3D3380 E00CE8C0 00000000 */  nop       
/* 3D3384 E00CE8C4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3D3388 E00CE8C8 C6400058 */  lwc1      $f0, 0x58($s2)
/* 3D338C E00CE8CC 461A0002 */  mul.s     $f0, $f0, $f26
/* 3D3390 E00CE8D0 00000000 */  nop       
/* 3D3394 E00CE8D4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3D3398 E00CE8D8 C6400078 */  lwc1      $f0, 0x78($s2)
/* 3D339C E00CE8DC 461A0002 */  mul.s     $f0, $f0, $f26
/* 3D33A0 E00CE8E0 00000000 */  nop       
/* 3D33A4 E00CE8E4 4405F000 */  mfc1      $a1, $f30
/* 3D33A8 E00CE8E8 4406F000 */  mfc1      $a2, $f30
/* 3D33AC E00CE8EC E7A0001C */  swc1      $f0, 0x1c($sp)
/* 3D33B0 E00CE8F0 8E470118 */  lw        $a3, 0x118($s2)
/* 3D33B4 E00CE8F4 0C080180 */  jal       func_E0200600
/* 3D33B8 E00CE8F8 27A40020 */   addiu    $a0, $sp, 0x20
/* 3D33BC E00CE8FC 02940018 */  mult      $s4, $s4
/* 3D33C0 E00CE900 00006012 */  mflo      $t4
/* 3D33C4 E00CE904 C6C00138 */  lwc1      $f0, 0x138($s6)
/* 3D33C8 E00CE908 448CE000 */  mtc1      $t4, $f28
/* 3D33CC E00CE90C 00000000 */  nop       
/* 3D33D0 E00CE910 4680E720 */  cvt.s.w   $f28, $f28
/* 3D33D4 E00CE914 461C0000 */  add.s     $f0, $f0, $f28
/* 3D33D8 E00CE918 3C06BCF5 */  lui       $a2, 0xbcf5
/* 3D33DC E00CE91C 34C6C28F */  ori       $a2, $a2, 0xc28f
/* 3D33E0 E00CE920 3C073F80 */  lui       $a3, 0x3f80
/* 3D33E4 E00CE924 44050000 */  mfc1      $a1, $f0
/* 3D33E8 E00CE928 3C013DCC */  lui       $at, 0x3dcc
/* 3D33EC E00CE92C 3421CCCD */  ori       $at, $at, 0xcccd
/* 3D33F0 E00CE930 44810000 */  mtc1      $at, $f0
/* 3D33F4 E00CE934 0260202D */  daddu     $a0, $s3, $zero
/* 3D33F8 E00CE938 0C080104 */  jal       func_E0200410
/* 3D33FC E00CE93C E7A00010 */   swc1     $f0, 0x10($sp)
/* 3D3400 E00CE940 0260202D */  daddu     $a0, $s3, $zero
/* 3D3404 E00CE944 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D3408 E00CE948 0C080114 */  jal       func_E0200450
/* 3D340C E00CE94C 00A0302D */   daddu    $a2, $a1, $zero
/* 3D3410 E00CE950 C6400098 */  lwc1      $f0, 0x98($s2)
/* 3D3414 E00CE954 8FAC00A0 */  lw        $t4, 0xa0($sp)
/* 3D3418 E00CE958 C7A600B8 */  lwc1      $f6, 0xb8($sp)
/* 3D341C E00CE95C 29820010 */  slti      $v0, $t4, 0x10
/* 3D3420 E00CE960 46060102 */  mul.s     $f4, $f0, $f6
/* 3D3424 E00CE964 00000000 */  nop       
/* 3D3428 E00CE968 1040000C */  beqz      $v0, .LE00CE99C
/* 3D342C E00CE96C 2402007F */   addiu    $v0, $zero, 0x7f
/* 3D3430 E00CE970 8FAC00A4 */  lw        $t4, 0xa4($sp)
/* 3D3434 E00CE974 3C013CA3 */  lui       $at, 0x3ca3
/* 3D3438 E00CE978 3421D70A */  ori       $at, $at, 0xd70a
/* 3D343C E00CE97C 44811000 */  mtc1      $at, $f2
/* 3D3440 E00CE980 004C1023 */  subu      $v0, $v0, $t4
/* 3D3444 E00CE984 44820000 */  mtc1      $v0, $f0
/* 3D3448 E00CE988 00000000 */  nop       
/* 3D344C E00CE98C 46800020 */  cvt.s.w   $f0, $f0
/* 3D3450 E00CE990 46020002 */  mul.s     $f0, $f0, $f2
/* 3D3454 E00CE994 00000000 */  nop       
/* 3D3458 E00CE998 46002100 */  add.s     $f4, $f4, $f0
.LE00CE99C:
/* 3D345C E00CE99C 0260202D */  daddu     $a0, $s3, $zero
/* 3D3460 E00CE9A0 44052000 */  mfc1      $a1, $f4
/* 3D3464 E00CE9A4 8FA600B8 */  lw        $a2, 0xb8($sp)
/* 3D3468 E00CE9A8 0C080110 */  jal       func_E0200440
/* 3D346C E00CE9AC 00A0382D */   daddu    $a3, $a1, $zero
/* 3D3470 E00CE9B0 0260202D */  daddu     $a0, $s3, $zero
/* 3D3474 E00CE9B4 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D3478 E00CE9B8 0C080114 */  jal       func_E0200450
/* 3D347C E00CE9BC 00A0302D */   daddu    $a2, $a1, $zero
/* 3D3480 E00CE9C0 C65400F8 */  lwc1      $f20, 0xf8($s2)
/* 3D3484 E00CE9C4 461AA502 */  mul.s     $f20, $f20, $f26
/* 3D3488 E00CE9C8 00000000 */  nop       
/* 3D348C E00CE9CC C65600B8 */  lwc1      $f22, 0xb8($s2)
/* 3D3490 E00CE9D0 0C080140 */  jal       func_E0200500
/* 3D3494 E00CE9D4 4600B306 */   mov.s    $f12, $f22
/* 3D3498 E00CE9D8 4600A602 */  mul.s     $f24, $f20, $f0
/* 3D349C E00CE9DC 00000000 */  nop       
/* 3D34A0 E00CE9E0 0C080144 */  jal       func_E0200510
/* 3D34A4 E00CE9E4 4600B306 */   mov.s    $f12, $f22
/* 3D34A8 E00CE9E8 4600A502 */  mul.s     $f20, $f20, $f0
/* 3D34AC E00CE9EC 00000000 */  nop       
/* 3D34B0 E00CE9F0 4406F000 */  mfc1      $a2, $f30
/* 3D34B4 E00CE9F4 4407A000 */  mfc1      $a3, $f20
/* 3D34B8 E00CE9F8 4405C000 */  mfc1      $a1, $f24
/* 3D34BC E00CE9FC 0C080108 */  jal       func_E0200420
/* 3D34C0 E00CEA00 0260202D */   daddu    $a0, $s3, $zero
/* 3D34C4 E00CEA04 0260202D */  daddu     $a0, $s3, $zero
/* 3D34C8 E00CEA08 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D34CC E00CEA0C 0C080114 */  jal       func_E0200450
/* 3D34D0 E00CEA10 00A0302D */   daddu    $a2, $a1, $zero
/* 3D34D4 E00CEA14 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D34D8 E00CEA18 96E50000 */  lhu       $a1, ($s7)
/* 3D34DC E00CEA1C 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 3D34E0 E00CEA20 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 3D34E4 E00CEA24 00052980 */  sll       $a1, $a1, 6
/* 3D34E8 E00CEA28 00BE2821 */  addu      $a1, $a1, $fp
/* 3D34EC E00CEA2C 0C080118 */  jal       func_E0200460
/* 3D34F0 E00CEA30 00452821 */   addu     $a1, $v0, $a1
/* 3D34F4 E00CEA34 3C050101 */  lui       $a1, 0x101
/* 3D34F8 E00CEA38 34A50020 */  ori       $a1, $a1, 0x20
/* 3D34FC E00CEA3C 8EA80000 */  lw        $t0, ($s5)
/* 3D3500 E00CEA40 96E70000 */  lhu       $a3, ($s7)
/* 3D3504 E00CEA44 3C03800A */  lui       $v1, %hi(D_8009A674)
/* 3D3508 E00CEA48 8C63A674 */  lw        $v1, %lo(D_8009A674)($v1)
/* 3D350C E00CEA4C 0100202D */  daddu     $a0, $t0, $zero
/* 3D3510 E00CEA50 25080008 */  addiu     $t0, $t0, 8
/* 3D3514 E00CEA54 3C0CDA38 */  lui       $t4, 0xda38
/* 3D3518 E00CEA58 30E2FFFF */  andi      $v0, $a3, 0xffff
/* 3D351C E00CEA5C 00021180 */  sll       $v0, $v0, 6
/* 3D3520 E00CEA60 005E1021 */  addu      $v0, $v0, $fp
/* 3D3524 E00CEA64 00621821 */  addu      $v1, $v1, $v0
/* 3D3528 E00CEA68 AC8C0000 */  sw        $t4, ($a0)
/* 3D352C E00CEA6C AC830004 */  sw        $v1, 4($a0)
/* 3D3530 E00CEA70 AD050000 */  sw        $a1, ($t0)
/* 3D3534 E00CEA74 8FAC00AC */  lw        $t4, 0xac($sp)
/* 3D3538 E00CEA78 26910001 */  addiu     $s1, $s4, 1
/* 3D353C E00CEA7C AD0C0004 */  sw        $t4, 4($t0)
/* 3D3540 E00CEA80 8FAC00C4 */  lw        $t4, 0xc4($sp)
/* 3D3544 E00CEA84 00118080 */  sll       $s0, $s1, 2
/* 3D3548 E00CEA88 AD0C0008 */  sw        $t4, 8($t0)
/* 3D354C E00CEA8C 240C0040 */  addiu     $t4, $zero, 0x40
/* 3D3550 E00CEA90 3C013F80 */  lui       $at, 0x3f80
/* 3D3554 E00CEA94 44813000 */  mtc1      $at, $f6
/* 3D3558 E00CEA98 02D08021 */  addu      $s0, $s6, $s0
/* 3D355C E00CEA9C AD0C000C */  sw        $t4, 0xc($t0)
/* 3D3560 E00CEAA0 E7A60010 */  swc1      $f6, 0x10($sp)
/* 3D3564 E00CEAA4 C6000038 */  lwc1      $f0, 0x38($s0)
/* 3D3568 E00CEAA8 461A0002 */  mul.s     $f0, $f0, $f26
/* 3D356C E00CEAAC 00000000 */  nop       
/* 3D3570 E00CEAB0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3D3574 E00CEAB4 C6000058 */  lwc1      $f0, 0x58($s0)
/* 3D3578 E00CEAB8 461A0002 */  mul.s     $f0, $f0, $f26
/* 3D357C E00CEABC 00000000 */  nop       
/* 3D3580 E00CEAC0 4406F000 */  mfc1      $a2, $f30
/* 3D3584 E00CEAC4 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D3588 E00CEAC8 24E70001 */  addiu     $a3, $a3, 1
/* 3D358C E00CEACC E7A00018 */  swc1      $f0, 0x18($sp)
/* 3D3590 E00CEAD0 C6000078 */  lwc1      $f0, 0x78($s0)
/* 3D3594 E00CEAD4 4405F000 */  mfc1      $a1, $f30
/* 3D3598 E00CEAD8 461A0002 */  mul.s     $f0, $f0, $f26
/* 3D359C E00CEADC 00000000 */  nop       
/* 3D35A0 E00CEAE0 25020008 */  addiu     $v0, $t0, 8
/* 3D35A4 E00CEAE4 AEA80000 */  sw        $t0, ($s5)
/* 3D35A8 E00CEAE8 A6E70000 */  sh        $a3, ($s7)
/* 3D35AC E00CEAEC AEA20000 */  sw        $v0, ($s5)
/* 3D35B0 E00CEAF0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 3D35B4 E00CEAF4 8E070118 */  lw        $a3, 0x118($s0)
/* 3D35B8 E00CEAF8 25080010 */  addiu     $t0, $t0, 0x10
/* 3D35BC E00CEAFC 0C080180 */  jal       func_E0200600
/* 3D35C0 E00CEB00 AEA80000 */   sw       $t0, ($s5)
/* 3D35C4 E00CEB04 C6C00138 */  lwc1      $f0, 0x138($s6)
/* 3D35C8 E00CEB08 461C0000 */  add.s     $f0, $f0, $f28
/* 3D35CC E00CEB0C 3C063CF5 */  lui       $a2, 0x3cf5
/* 3D35D0 E00CEB10 34C6C28F */  ori       $a2, $a2, 0xc28f
/* 3D35D4 E00CEB14 3C073F80 */  lui       $a3, 0x3f80
/* 3D35D8 E00CEB18 44050000 */  mfc1      $a1, $f0
/* 3D35DC E00CEB1C 0260202D */  daddu     $a0, $s3, $zero
/* 3D35E0 E00CEB20 0C080104 */  jal       func_E0200410
/* 3D35E4 E00CEB24 E7BE0010 */   swc1     $f30, 0x10($sp)
/* 3D35E8 E00CEB28 0260202D */  daddu     $a0, $s3, $zero
/* 3D35EC E00CEB2C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D35F0 E00CEB30 0C080114 */  jal       func_E0200450
/* 3D35F4 E00CEB34 00A0302D */   daddu    $a2, $a1, $zero
/* 3D35F8 E00CEB38 C6000098 */  lwc1      $f0, 0x98($s0)
/* 3D35FC E00CEB3C C7A600B8 */  lwc1      $f6, 0xb8($sp)
/* 3D3600 E00CEB40 46060002 */  mul.s     $f0, $f0, $f6
/* 3D3604 E00CEB44 00000000 */  nop       
/* 3D3608 E00CEB48 0260202D */  daddu     $a0, $s3, $zero
/* 3D360C E00CEB4C 44050000 */  mfc1      $a1, $f0
/* 3D3610 E00CEB50 44063000 */  mfc1      $a2, $f6
/* 3D3614 E00CEB54 0C080110 */  jal       func_E0200440
/* 3D3618 E00CEB58 00A0382D */   daddu    $a3, $a1, $zero
/* 3D361C E00CEB5C 0260202D */  daddu     $a0, $s3, $zero
/* 3D3620 E00CEB60 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D3624 E00CEB64 0C080114 */  jal       func_E0200450
/* 3D3628 E00CEB68 00A0302D */   daddu    $a2, $a1, $zero
/* 3D362C E00CEB6C C65400F8 */  lwc1      $f20, 0xf8($s2)
/* 3D3630 E00CEB70 461AA502 */  mul.s     $f20, $f20, $f26
/* 3D3634 E00CEB74 00000000 */  nop       
/* 3D3638 E00CEB78 0C080140 */  jal       func_E0200500
/* 3D363C E00CEB7C C64C00B8 */   lwc1     $f12, 0xb8($s2)
/* 3D3640 E00CEB80 4600A582 */  mul.s     $f22, $f20, $f0
/* 3D3644 E00CEB84 00000000 */  nop       
/* 3D3648 E00CEB88 0C080144 */  jal       func_E0200510
/* 3D364C E00CEB8C C64C00B8 */   lwc1     $f12, 0xb8($s2)
/* 3D3650 E00CEB90 4600A502 */  mul.s     $f20, $f20, $f0
/* 3D3654 E00CEB94 00000000 */  nop       
/* 3D3658 E00CEB98 4406F000 */  mfc1      $a2, $f30
/* 3D365C E00CEB9C 4407A000 */  mfc1      $a3, $f20
/* 3D3660 E00CEBA0 4405B000 */  mfc1      $a1, $f22
/* 3D3664 E00CEBA4 0C080108 */  jal       func_E0200420
/* 3D3668 E00CEBA8 0260202D */   daddu    $a0, $s3, $zero
/* 3D366C E00CEBAC 0260202D */  daddu     $a0, $s3, $zero
/* 3D3670 E00CEBB0 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D3674 E00CEBB4 0C080114 */  jal       func_E0200450
/* 3D3678 E00CEBB8 00A0302D */   daddu    $a2, $a1, $zero
/* 3D367C E00CEBBC 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D3680 E00CEBC0 96E50000 */  lhu       $a1, ($s7)
/* 3D3684 E00CEBC4 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 3D3688 E00CEBC8 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 3D368C E00CEBCC 00052980 */  sll       $a1, $a1, 6
/* 3D3690 E00CEBD0 00BE2821 */  addu      $a1, $a1, $fp
/* 3D3694 E00CEBD4 0C080118 */  jal       func_E0200460
/* 3D3698 E00CEBD8 00452821 */   addu     $a1, $v0, $a1
/* 3D369C E00CEBDC 3C080101 */  lui       $t0, 0x101
/* 3D36A0 E00CEBE0 35080040 */  ori       $t0, $t0, 0x40
/* 3D36A4 E00CEBE4 3C090100 */  lui       $t1, 0x100
/* 3D36A8 E00CEBE8 3529007C */  ori       $t1, $t1, 0x7c
/* 3D36AC E00CEBEC 00142900 */  sll       $a1, $s4, 4
/* 3D36B0 E00CEBF0 8EA40000 */  lw        $a0, ($s5)
/* 3D36B4 E00CEBF4 96E30000 */  lhu       $v1, ($s7)
/* 3D36B8 E00CEBF8 0080382D */  daddu     $a3, $a0, $zero
/* 3D36BC E00CEBFC 24840008 */  addiu     $a0, $a0, 8
/* 3D36C0 E00CEC00 3C0CDA38 */  lui       $t4, 0xda38
/* 3D36C4 E00CEC04 24620001 */  addiu     $v0, $v1, 1
/* 3D36C8 E00CEC08 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3D36CC E00CEC0C 00031980 */  sll       $v1, $v1, 6
/* 3D36D0 E00CEC10 AEA40000 */  sw        $a0, ($s5)
/* 3D36D4 E00CEC14 ACEC0000 */  sw        $t4, ($a3)
/* 3D36D8 E00CEC18 A6E20000 */  sh        $v0, ($s7)
/* 3D36DC E00CEC1C 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 3D36E0 E00CEC20 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 3D36E4 E00CEC24 007E1821 */  addu      $v1, $v1, $fp
/* 3D36E8 E00CEC28 00431021 */  addu      $v0, $v0, $v1
/* 3D36EC E00CEC2C ACE20004 */  sw        $v0, 4($a3)
/* 3D36F0 E00CEC30 24820008 */  addiu     $v0, $a0, 8
/* 3D36F4 E00CEC34 AEA20000 */  sw        $v0, ($s5)
/* 3D36F8 E00CEC38 AC880000 */  sw        $t0, ($a0)
/* 3D36FC E00CEC3C 8FAC00AC */  lw        $t4, 0xac($sp)
/* 3D3700 E00CEC40 001430C0 */  sll       $a2, $s4, 3
/* 3D3704 E00CEC44 25820100 */  addiu     $v0, $t4, 0x100
/* 3D3708 E00CEC48 AC820004 */  sw        $v0, 4($a0)
/* 3D370C E00CEC4C 24820010 */  addiu     $v0, $a0, 0x10
/* 3D3710 E00CEC50 AEA20000 */  sw        $v0, ($s5)
/* 3D3714 E00CEC54 8FAC00C4 */  lw        $t4, 0xc4($sp)
/* 3D3718 E00CEC58 24820018 */  addiu     $v0, $a0, 0x18
/* 3D371C E00CEC5C AC8C0008 */  sw        $t4, 8($a0)
/* 3D3720 E00CEC60 240C0040 */  addiu     $t4, $zero, 0x40
/* 3D3724 E00CEC64 AC8C000C */  sw        $t4, 0xc($a0)
/* 3D3728 E00CEC68 AEA20000 */  sw        $v0, ($s5)
/* 3D372C E00CEC6C 8FAC00B0 */  lw        $t4, 0xb0($sp)
/* 3D3730 E00CEC70 0220A02D */  daddu     $s4, $s1, $zero
/* 3D3734 E00CEC74 01852821 */  addu      $a1, $t4, $a1
/* 3D3738 E00CEC78 30A20FFF */  andi      $v0, $a1, 0xfff
/* 3D373C E00CEC7C 00021300 */  sll       $v0, $v0, 0xc
/* 3D3740 E00CEC80 3C0CF200 */  lui       $t4, 0xf200
/* 3D3744 E00CEC84 004C1025 */  or        $v0, $v0, $t4
/* 3D3748 E00CEC88 24A5003F */  addiu     $a1, $a1, 0x3f
/* 3D374C E00CEC8C 00052880 */  sll       $a1, $a1, 2
/* 3D3750 E00CEC90 30A50FFF */  andi      $a1, $a1, 0xfff
/* 3D3754 E00CEC94 00052B00 */  sll       $a1, $a1, 0xc
/* 3D3758 E00CEC98 34A5007C */  ori       $a1, $a1, 0x7c
/* 3D375C E00CEC9C AC820010 */  sw        $v0, 0x10($a0)
/* 3D3760 E00CECA0 24820020 */  addiu     $v0, $a0, 0x20
/* 3D3764 E00CECA4 AC850014 */  sw        $a1, 0x14($a0)
/* 3D3768 E00CECA8 AEA20000 */  sw        $v0, ($s5)
/* 3D376C E00CECAC 8FAC00B4 */  lw        $t4, 0xb4($sp)
/* 3D3770 E00CECB0 3C0ADE00 */  lui       $t2, 0xde00
/* 3D3774 E00CECB4 01863021 */  addu      $a2, $t4, $a2
/* 3D3778 E00CECB8 30C20FFF */  andi      $v0, $a2, 0xfff
/* 3D377C E00CECBC 00021300 */  sll       $v0, $v0, 0xc
/* 3D3780 E00CECC0 3C0CF200 */  lui       $t4, 0xf200
/* 3D3784 E00CECC4 004C1025 */  or        $v0, $v0, $t4
/* 3D3788 E00CECC8 24C6003F */  addiu     $a2, $a2, 0x3f
/* 3D378C E00CECCC 00063080 */  sll       $a2, $a2, 2
/* 3D3790 E00CECD0 30C60FFF */  andi      $a2, $a2, 0xfff
/* 3D3794 E00CECD4 00063300 */  sll       $a2, $a2, 0xc
/* 3D3798 E00CECD8 00C93025 */  or        $a2, $a2, $t1
/* 3D379C E00CECDC AC820018 */  sw        $v0, 0x18($a0)
/* 3D37A0 E00CECE0 24820028 */  addiu     $v0, $a0, 0x28
/* 3D37A4 E00CECE4 AC86001C */  sw        $a2, 0x1c($a0)
/* 3D37A8 E00CECE8 AEA20000 */  sw        $v0, ($s5)
/* 3D37AC E00CECEC AC8A0020 */  sw        $t2, 0x20($a0)
/* 3D37B0 E00CECF0 8FAC00A8 */  lw        $t4, 0xa8($sp)
/* 3D37B4 E00CECF4 2A820007 */  slti      $v0, $s4, 7
/* 3D37B8 E00CECF8 1440FEEA */  bnez      $v0, .LE00CE8A4
/* 3D37BC E00CECFC AC8C0024 */   sw       $t4, 0x24($a0)
/* 3D37C0 E00CED00 3C05D9FF */  lui       $a1, 0xd9ff
/* 3D37C4 E00CED04 34A5F9FF */  ori       $a1, $a1, 0xf9ff
/* 3D37C8 E00CED08 3C09D838 */  lui       $t1, 0xd838
/* 3D37CC E00CED0C 3C07800A */  lui       $a3, %hi(D_8009A66C)
/* 3D37D0 E00CED10 24E7A66C */  addiu     $a3, $a3, %lo(D_8009A66C)
/* 3D37D4 E00CED14 35290002 */  ori       $t1, $t1, 2
/* 3D37D8 E00CED18 8CE40000 */  lw        $a0, ($a3)
/* 3D37DC E00CED1C 3C02DF00 */  lui       $v0, 0xdf00
/* 3D37E0 E00CED20 0080182D */  daddu     $v1, $a0, $zero
/* 3D37E4 E00CED24 24840008 */  addiu     $a0, $a0, 8
/* 3D37E8 E00CED28 ACE40000 */  sw        $a0, ($a3)
/* 3D37EC E00CED2C AC620000 */  sw        $v0, ($v1)
/* 3D37F0 E00CED30 AC600004 */  sw        $zero, 4($v1)
/* 3D37F4 E00CED34 8FAC00C0 */  lw        $t4, 0xc0($sp)
/* 3D37F8 E00CED38 3C02DE01 */  lui       $v0, 0xde01
/* 3D37FC E00CED3C AD820000 */  sw        $v0, ($t4)
/* 3D3800 E00CED40 24820008 */  addiu     $v0, $a0, 8
/* 3D3804 E00CED44 AD840004 */  sw        $a0, 4($t4)
/* 3D3808 E00CED48 ACE20000 */  sw        $v0, ($a3)
/* 3D380C E00CED4C 24820010 */  addiu     $v0, $a0, 0x10
/* 3D3810 E00CED50 AC850000 */  sw        $a1, ($a0)
/* 3D3814 E00CED54 AC800004 */  sw        $zero, 4($a0)
/* 3D3818 E00CED58 ACE20000 */  sw        $v0, ($a3)
/* 3D381C E00CED5C 3C02FA00 */  lui       $v0, 0xfa00
/* 3D3820 E00CED60 AC820008 */  sw        $v0, 8($a0)
/* 3D3824 E00CED64 92C2001B */  lbu       $v0, 0x1b($s6)
/* 3D3828 E00CED68 92C5001F */  lbu       $a1, 0x1f($s6)
/* 3D382C E00CED6C 92C60023 */  lbu       $a2, 0x23($s6)
/* 3D3830 E00CED70 24830018 */  addiu     $v1, $a0, 0x18
/* 3D3834 E00CED74 ACE30000 */  sw        $v1, ($a3)
/* 3D3838 E00CED78 3C03FB00 */  lui       $v1, 0xfb00
/* 3D383C E00CED7C AC830010 */  sw        $v1, 0x10($a0)
/* 3D3840 E00CED80 8FAC00A4 */  lw        $t4, 0xa4($sp)
/* 3D3844 E00CED84 00021600 */  sll       $v0, $v0, 0x18
/* 3D3848 E00CED88 00052C00 */  sll       $a1, $a1, 0x10
/* 3D384C E00CED8C 00451025 */  or        $v0, $v0, $a1
/* 3D3850 E00CED90 00063200 */  sll       $a2, $a2, 8
/* 3D3854 E00CED94 00461025 */  or        $v0, $v0, $a2
/* 3D3858 E00CED98 318300FF */  andi      $v1, $t4, 0xff
/* 3D385C E00CED9C 00431025 */  or        $v0, $v0, $v1
/* 3D3860 E00CEDA0 AC82000C */  sw        $v0, 0xc($a0)
/* 3D3864 E00CEDA4 92C3002B */  lbu       $v1, 0x2b($s6)
/* 3D3868 E00CEDA8 92C6002F */  lbu       $a2, 0x2f($s6)
/* 3D386C E00CEDAC 92C80033 */  lbu       $t0, 0x33($s6)
/* 3D3870 E00CEDB0 24820020 */  addiu     $v0, $a0, 0x20
/* 3D3874 E00CEDB4 ACE20000 */  sw        $v0, ($a3)
/* 3D3878 E00CEDB8 24820028 */  addiu     $v0, $a0, 0x28
/* 3D387C E00CEDBC AC8A0018 */  sw        $t2, 0x18($a0)
/* 3D3880 E00CEDC0 8FAC00BC */  lw        $t4, 0xbc($sp)
/* 3D3884 E00CEDC4 24050040 */  addiu     $a1, $zero, 0x40
/* 3D3888 E00CEDC8 AC8C001C */  sw        $t4, 0x1c($a0)
/* 3D388C E00CEDCC ACE20000 */  sw        $v0, ($a3)
/* 3D3890 E00CEDD0 24820030 */  addiu     $v0, $a0, 0x30
/* 3D3894 E00CEDD4 00031E00 */  sll       $v1, $v1, 0x18
/* 3D3898 E00CEDD8 00063400 */  sll       $a2, $a2, 0x10
/* 3D389C E00CEDDC 00661825 */  or        $v1, $v1, $a2
/* 3D38A0 E00CEDE0 00084200 */  sll       $t0, $t0, 8
/* 3D38A4 E00CEDE4 00681825 */  or        $v1, $v1, $t0
/* 3D38A8 E00CEDE8 34630020 */  ori       $v1, $v1, 0x20
/* 3D38AC E00CEDEC AC890020 */  sw        $t1, 0x20($a0)
/* 3D38B0 E00CEDF0 AC850024 */  sw        $a1, 0x24($a0)
/* 3D38B4 E00CEDF4 ACE20000 */  sw        $v0, ($a3)
/* 3D38B8 E00CEDF8 AC890028 */  sw        $t1, 0x28($a0)
/* 3D38BC E00CEDFC AC85002C */  sw        $a1, 0x2c($a0)
/* 3D38C0 E00CEE00 AC830014 */  sw        $v1, 0x14($a0)
/* 3D38C4 E00CEE04 8FBF00EC */  lw        $ra, 0xec($sp)
/* 3D38C8 E00CEE08 8FBE00E8 */  lw        $fp, 0xe8($sp)
/* 3D38CC E00CEE0C 8FB700E4 */  lw        $s7, 0xe4($sp)
/* 3D38D0 E00CEE10 8FB600E0 */  lw        $s6, 0xe0($sp)
/* 3D38D4 E00CEE14 8FB500DC */  lw        $s5, 0xdc($sp)
/* 3D38D8 E00CEE18 8FB400D8 */  lw        $s4, 0xd8($sp)
/* 3D38DC E00CEE1C 8FB300D4 */  lw        $s3, 0xd4($sp)
/* 3D38E0 E00CEE20 8FB200D0 */  lw        $s2, 0xd0($sp)
/* 3D38E4 E00CEE24 8FB100CC */  lw        $s1, 0xcc($sp)
/* 3D38E8 E00CEE28 8FB000C8 */  lw        $s0, 0xc8($sp)
/* 3D38EC E00CEE2C D7BE0118 */  ldc1      $f30, 0x118($sp)
/* 3D38F0 E00CEE30 D7BC0110 */  ldc1      $f28, 0x110($sp)
/* 3D38F4 E00CEE34 D7BA0108 */  ldc1      $f26, 0x108($sp)
/* 3D38F8 E00CEE38 D7B80100 */  ldc1      $f24, 0x100($sp)
/* 3D38FC E00CEE3C D7B600F8 */  ldc1      $f22, 0xf8($sp)
/* 3D3900 E00CEE40 D7B400F0 */  ldc1      $f20, 0xf0($sp)
/* 3D3904 E00CEE44 03E00008 */  jr        $ra
/* 3D3908 E00CEE48 27BD0120 */   addiu    $sp, $sp, 0x120
/* 3D390C E00CEE4C 00000000 */  nop       
