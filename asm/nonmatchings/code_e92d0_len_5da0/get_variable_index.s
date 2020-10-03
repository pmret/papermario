.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_variable_index
/* EC758 802C7DA8 3C02EFE8 */  lui       $v0, 0xefe8
/* EC75C 802C7DAC 34422080 */  ori       $v0, $v0, 0x2080
/* EC760 802C7DB0 0045102A */  slt       $v0, $v0, $a1
/* EC764 802C7DB4 14400003 */  bnez      $v0, .L802C7DC4
/* EC768 802C7DB8 3C02F119 */   lui      $v0, 0xf119
.L802C7DBC:
/* EC76C 802C7DBC 03E00008 */  jr        $ra
/* EC770 802C7DC0 00A0102D */   daddu    $v0, $a1, $zero
.L802C7DC4:
/* EC774 802C7DC4 34424D80 */  ori       $v0, $v0, 0x4d80
/* EC778 802C7DC8 0045102A */  slt       $v0, $v0, $a1
/* EC77C 802C7DCC 1040FFFB */  beqz      $v0, .L802C7DBC
/* EC780 802C7DD0 3C02F2E3 */   lui      $v0, 0xf2e3
/* EC784 802C7DD4 34421100 */  ori       $v0, $v0, 0x1100
/* EC788 802C7DD8 0045102A */  slt       $v0, $v0, $a1
/* EC78C 802C7DDC 1040FFF7 */  beqz      $v0, .L802C7DBC
/* EC790 802C7DE0 3C02F414 */   lui      $v0, 0xf414
/* EC794 802C7DE4 34423E00 */  ori       $v0, $v0, 0x3e00
/* EC798 802C7DE8 0045102A */  slt       $v0, $v0, $a1
/* EC79C 802C7DEC 54400005 */  bnel      $v0, $zero, .L802C7E04
/* EC7A0 802C7DF0 3C02F545 */   lui      $v0, 0xf545
/* EC7A4 802C7DF4 3C020C84 */  lui       $v0, 0xc84
/* EC7A8 802C7DF8 34425880 */  ori       $v0, $v0, 0x5880
/* EC7AC 802C7DFC 03E00008 */  jr        $ra
/* EC7B0 802C7E00 00A21021 */   addu     $v0, $a1, $v0
.L802C7E04:
/* EC7B4 802C7E04 34426B00 */  ori       $v0, $v0, 0x6b00
/* EC7B8 802C7E08 0045102A */  slt       $v0, $v0, $a1
/* EC7BC 802C7E0C 54400005 */  bnel      $v0, $zero, .L802C7E24
/* EC7C0 802C7E10 3C02F676 */   lui      $v0, 0xf676
/* EC7C4 802C7E14 3C020B53 */  lui       $v0, 0xb53
/* EC7C8 802C7E18 34422B80 */  ori       $v0, $v0, 0x2b80
/* EC7CC 802C7E1C 03E00008 */  jr        $ra
/* EC7D0 802C7E20 00A21021 */   addu     $v0, $a1, $v0
.L802C7E24:
/* EC7D4 802C7E24 34429800 */  ori       $v0, $v0, 0x9800
/* EC7D8 802C7E28 0045102A */  slt       $v0, $v0, $a1
/* EC7DC 802C7E2C 54400005 */  bnel      $v0, $zero, .L802C7E44
/* EC7E0 802C7E30 3C02F7A7 */   lui      $v0, 0xf7a7
/* EC7E4 802C7E34 3C020A21 */  lui       $v0, 0xa21
/* EC7E8 802C7E38 3442FE80 */  ori       $v0, $v0, 0xfe80
/* EC7EC 802C7E3C 03E00008 */  jr        $ra
/* EC7F0 802C7E40 00A21021 */   addu     $v0, $a1, $v0
.L802C7E44:
/* EC7F4 802C7E44 3442C500 */  ori       $v0, $v0, 0xc500
/* EC7F8 802C7E48 0045102A */  slt       $v0, $v0, $a1
/* EC7FC 802C7E4C 54400005 */  bnel      $v0, $zero, .L802C7E64
/* EC800 802C7E50 3C02F8D8 */   lui      $v0, 0xf8d8
/* EC804 802C7E54 3C0208F0 */  lui       $v0, 0x8f0
/* EC808 802C7E58 3442D180 */  ori       $v0, $v0, 0xd180
/* EC80C 802C7E5C 03E00008 */  jr        $ra
/* EC810 802C7E60 00A21021 */   addu     $v0, $a1, $v0
.L802C7E64:
/* EC814 802C7E64 3442F200 */  ori       $v0, $v0, 0xf200
/* EC818 802C7E68 0045102A */  slt       $v0, $v0, $a1
/* EC81C 802C7E6C 54400005 */  bnel      $v0, $zero, .L802C7E84
/* EC820 802C7E70 3C02FA0A */   lui      $v0, 0xfa0a
/* EC824 802C7E74 3C0207BF */  lui       $v0, 0x7bf
/* EC828 802C7E78 3442A480 */  ori       $v0, $v0, 0xa480
/* EC82C 802C7E7C 03E00008 */  jr        $ra
/* EC830 802C7E80 00A21021 */   addu     $v0, $a1, $v0
.L802C7E84:
/* EC834 802C7E84 34421F00 */  ori       $v0, $v0, 0x1f00
/* EC838 802C7E88 0045102A */  slt       $v0, $v0, $a1
/* EC83C 802C7E8C 54400005 */  bnel      $v0, $zero, .L802C7EA4
/* EC840 802C7E90 3C02FB3B */   lui      $v0, 0xfb3b
/* EC844 802C7E94 3C02068E */  lui       $v0, 0x68e
/* EC848 802C7E98 34427780 */  ori       $v0, $v0, 0x7780
/* EC84C 802C7E9C 03E00008 */  jr        $ra
/* EC850 802C7EA0 00A21021 */   addu     $v0, $a1, $v0
.L802C7EA4:
/* EC854 802C7EA4 34424C00 */  ori       $v0, $v0, 0x4c00
/* EC858 802C7EA8 0045102A */  slt       $v0, $v0, $a1
/* EC85C 802C7EAC 54400005 */  bnel      $v0, $zero, .L802C7EC4
/* EC860 802C7EB0 3C02FC6C */   lui      $v0, 0xfc6c
/* EC864 802C7EB4 3C02055D */  lui       $v0, 0x55d
/* EC868 802C7EB8 34424A80 */  ori       $v0, $v0, 0x4a80
/* EC86C 802C7EBC 03E00008 */  jr        $ra
/* EC870 802C7EC0 00A21021 */   addu     $v0, $a1, $v0
.L802C7EC4:
/* EC874 802C7EC4 34427900 */  ori       $v0, $v0, 0x7900
/* EC878 802C7EC8 0045102A */  slt       $v0, $v0, $a1
/* EC87C 802C7ECC 54400005 */  bnel      $v0, $zero, .L802C7EE4
/* EC880 802C7ED0 3C02FD9D */   lui      $v0, 0xfd9d
/* EC884 802C7ED4 3C02042C */  lui       $v0, 0x42c
/* EC888 802C7ED8 34421D80 */  ori       $v0, $v0, 0x1d80
/* EC88C 802C7EDC 03E00008 */  jr        $ra
/* EC890 802C7EE0 00A21021 */   addu     $v0, $a1, $v0
.L802C7EE4:
/* EC894 802C7EE4 3442A600 */  ori       $v0, $v0, 0xa600
/* EC898 802C7EE8 0045102A */  slt       $v0, $v0, $a1
/* EC89C 802C7EEC 54400005 */  bnel      $v0, $zero, .L802C7F04
/* EC8A0 802C7EF0 3C02FECE */   lui      $v0, 0xfece
/* EC8A4 802C7EF4 3C0202FA */  lui       $v0, 0x2fa
/* EC8A8 802C7EF8 3442F080 */  ori       $v0, $v0, 0xf080
/* EC8AC 802C7EFC 03E00008 */  jr        $ra
/* EC8B0 802C7F00 00A21021 */   addu     $v0, $a1, $v0
.L802C7F04:
/* EC8B4 802C7F04 3442D300 */  ori       $v0, $v0, 0xd300
/* EC8B8 802C7F08 0045102A */  slt       $v0, $v0, $a1
/* EC8BC 802C7F0C 1440FFAB */  bnez      $v0, .L802C7DBC
/* EC8C0 802C7F10 3C0201C9 */   lui      $v0, 0x1c9
/* EC8C4 802C7F14 3442C380 */  ori       $v0, $v0, 0xc380
/* EC8C8 802C7F18 03E00008 */  jr        $ra
/* EC8CC 802C7F1C 00A21021 */   addu     $v0, $a1, $v0
