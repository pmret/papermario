.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_variable
/* EC46C 802C7ABC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EC470 802C7AC0 3C07EFE8 */  lui       $a3, 0xefe8
/* EC474 802C7AC4 34E72080 */  ori       $a3, $a3, 0x2080
/* EC478 802C7AC8 00E5102A */  slt       $v0, $a3, $a1
/* EC47C 802C7ACC 104000B2 */  beqz      $v0, .L802C7D98
/* EC480 802C7AD0 AFBF0010 */   sw       $ra, 0x10($sp)
/* EC484 802C7AD4 3C02F119 */  lui       $v0, 0xf119
/* EC488 802C7AD8 34424D80 */  ori       $v0, $v0, 0x4d80
/* EC48C 802C7ADC 0045102A */  slt       $v0, $v0, $a1
/* EC490 802C7AE0 104000AD */  beqz      $v0, .L802C7D98
/* EC494 802C7AE4 3C06F2E3 */   lui      $a2, 0xf2e3
/* EC498 802C7AE8 34C61100 */  ori       $a2, $a2, 0x1100
/* EC49C 802C7AEC 00C5102A */  slt       $v0, $a2, $a1
/* EC4A0 802C7AF0 14400007 */  bnez      $v0, .L802C7B10
/* EC4A4 802C7AF4 3C02F414 */   lui      $v0, 0xf414
/* EC4A8 802C7AF8 0C0B1248 */  jal       fixed_var_to_float
/* EC4AC 802C7AFC 00A0202D */   daddu    $a0, $a1, $zero
/* EC4B0 802C7B00 4600008D */  trunc.w.s $f2, $f0
/* EC4B4 802C7B04 44021000 */  mfc1      $v0, $f2
/* EC4B8 802C7B08 080B1F67 */  j         .L802C7D9C
/* EC4BC 802C7B0C 00000000 */   nop      
.L802C7B10:
/* EC4C0 802C7B10 34423E00 */  ori       $v0, $v0, 0x3e00
/* EC4C4 802C7B14 0045102A */  slt       $v0, $v0, $a1
/* EC4C8 802C7B18 14400011 */  bnez      $v0, .L802C7B60
/* EC4CC 802C7B1C 3C02F545 */   lui      $v0, 0xf545
/* EC4D0 802C7B20 3C020C84 */  lui       $v0, 0xc84
/* EC4D4 802C7B24 34425880 */  ori       $v0, $v0, 0x5880
/* EC4D8 802C7B28 00A22821 */  addu      $a1, $a1, $v0
/* EC4DC 802C7B2C 04A10002 */  bgez      $a1, .L802C7B38
/* EC4E0 802C7B30 00A0182D */   daddu    $v1, $a1, $zero
/* EC4E4 802C7B34 24A3001F */  addiu     $v1, $a1, 0x1f
.L802C7B38:
/* EC4E8 802C7B38 00033143 */  sra       $a2, $v1, 5
/* EC4EC 802C7B3C 00C0182D */  daddu     $v1, $a2, $zero
/* EC4F0 802C7B40 00031140 */  sll       $v0, $v1, 5
/* EC4F4 802C7B44 00A23023 */  subu      $a2, $a1, $v0
/* EC4F8 802C7B48 8C820140 */  lw        $v0, 0x140($a0)
/* EC4FC 802C7B4C 00031880 */  sll       $v1, $v1, 2
/* EC500 802C7B50 00621821 */  addu      $v1, $v1, $v0
/* EC504 802C7B54 8C630000 */  lw        $v1, ($v1)
/* EC508 802C7B58 080B1F37 */  j         .L802C7CDC
/* EC50C 802C7B5C 24020001 */   addiu    $v0, $zero, 1
.L802C7B60:
/* EC510 802C7B60 34426B00 */  ori       $v0, $v0, 0x6b00
/* EC514 802C7B64 0045102A */  slt       $v0, $v0, $a1
/* EC518 802C7B68 1440000D */  bnez      $v0, .L802C7BA0
/* EC51C 802C7B6C 3C02F676 */   lui      $v0, 0xf676
/* EC520 802C7B70 3C020B53 */  lui       $v0, 0xb53
/* EC524 802C7B74 34422B80 */  ori       $v0, $v0, 0x2b80
/* EC528 802C7B78 00A22821 */  addu      $a1, $a1, $v0
/* EC52C 802C7B7C 8C83013C */  lw        $v1, 0x13c($a0)
/* EC530 802C7B80 00051080 */  sll       $v0, $a1, 2
/* EC534 802C7B84 00431021 */  addu      $v0, $v0, $v1
/* EC538 802C7B88 8C450000 */  lw        $a1, ($v0)
/* EC53C 802C7B8C 00E5102A */  slt       $v0, $a3, $a1
/* EC540 802C7B90 10400081 */  beqz      $v0, .L802C7D98
/* EC544 802C7B94 00C5102A */   slt      $v0, $a2, $a1
/* EC548 802C7B98 080B1F5F */  j         .L802C7D7C
/* EC54C 802C7B9C 00000000 */   nop      
.L802C7BA0:
/* EC550 802C7BA0 34429800 */  ori       $v0, $v0, 0x9800
/* EC554 802C7BA4 0045102A */  slt       $v0, $v0, $a1
/* EC558 802C7BA8 14400007 */  bnez      $v0, .L802C7BC8
/* EC55C 802C7BAC 3C02F7A7 */   lui      $v0, 0xf7a7
/* EC560 802C7BB0 3C040A21 */  lui       $a0, 0xa21
/* EC564 802C7BB4 3484FE80 */  ori       $a0, $a0, 0xfe80
/* EC568 802C7BB8 0C05154E */  jal       get_global_byte
/* EC56C 802C7BBC 00A42021 */   addu     $a0, $a1, $a0
/* EC570 802C7BC0 080B1F67 */  j         .L802C7D9C
/* EC574 802C7BC4 00000000 */   nop      
.L802C7BC8:
/* EC578 802C7BC8 3442C500 */  ori       $v0, $v0, 0xc500
/* EC57C 802C7BCC 0045102A */  slt       $v0, $v0, $a1
/* EC580 802C7BD0 14400007 */  bnez      $v0, .L802C7BF0
/* EC584 802C7BD4 3C02F8D8 */   lui      $v0, 0xf8d8
/* EC588 802C7BD8 3C0408F0 */  lui       $a0, 0x8f0
/* EC58C 802C7BDC 3484D180 */  ori       $a0, $a0, 0xd180
/* EC590 802C7BE0 0C051594 */  jal       get_area_byte
/* EC594 802C7BE4 00A42021 */   addu     $a0, $a1, $a0
/* EC598 802C7BE8 080B1F67 */  j         .L802C7D9C
/* EC59C 802C7BEC 00000000 */   nop      
.L802C7BF0:
/* EC5A0 802C7BF0 3442F200 */  ori       $v0, $v0, 0xf200
/* EC5A4 802C7BF4 0045102A */  slt       $v0, $v0, $a1
/* EC5A8 802C7BF8 14400007 */  bnez      $v0, .L802C7C18
/* EC5AC 802C7BFC 3C02FA0A */   lui      $v0, 0xfa0a
/* EC5B0 802C7C00 3C0407BF */  lui       $a0, 0x7bf
/* EC5B4 802C7C04 3484A480 */  ori       $a0, $a0, 0xa480
/* EC5B8 802C7C08 0C05152F */  jal       get_global_flag
/* EC5BC 802C7C0C 00A42021 */   addu     $a0, $a1, $a0
/* EC5C0 802C7C10 080B1F67 */  j         .L802C7D9C
/* EC5C4 802C7C14 00000000 */   nop      
.L802C7C18:
/* EC5C8 802C7C18 34421F00 */  ori       $v0, $v0, 0x1f00
/* EC5CC 802C7C1C 0045102A */  slt       $v0, $v0, $a1
/* EC5D0 802C7C20 14400007 */  bnez      $v0, .L802C7C40
/* EC5D4 802C7C24 3C02FB3B */   lui      $v0, 0xfb3b
/* EC5D8 802C7C28 3C04068E */  lui       $a0, 0x68e
/* EC5DC 802C7C2C 34847780 */  ori       $a0, $a0, 0x7780
/* EC5E0 802C7C30 0C05157C */  jal       get_area_flag
/* EC5E4 802C7C34 00A42021 */   addu     $a0, $a1, $a0
/* EC5E8 802C7C38 080B1F67 */  j         .L802C7D9C
/* EC5EC 802C7C3C 00000000 */   nop      
.L802C7C40:
/* EC5F0 802C7C40 34424C00 */  ori       $v0, $v0, 0x4c00
/* EC5F4 802C7C44 0045102A */  slt       $v0, $v0, $a1
/* EC5F8 802C7C48 14400012 */  bnez      $v0, .L802C7C94
/* EC5FC 802C7C4C 3C02FC6C */   lui      $v0, 0xfc6c
/* EC600 802C7C50 3C02055D */  lui       $v0, 0x55d
/* EC604 802C7C54 34424A80 */  ori       $v0, $v0, 0x4a80
/* EC608 802C7C58 00A22821 */  addu      $a1, $a1, $v0
/* EC60C 802C7C5C 04A10002 */  bgez      $a1, .L802C7C68
/* EC610 802C7C60 00A0182D */   daddu    $v1, $a1, $zero
/* EC614 802C7C64 24A3001F */  addiu     $v1, $a1, 0x1f
.L802C7C68:
/* EC618 802C7C68 00033143 */  sra       $a2, $v1, 5
/* EC61C 802C7C6C 00C0182D */  daddu     $v1, $a2, $zero
/* EC620 802C7C70 00031140 */  sll       $v0, $v1, 5
/* EC624 802C7C74 00A23023 */  subu      $a2, $a1, $v0
/* EC628 802C7C78 3C02802E */  lui       $v0, 0x802e
/* EC62C 802C7C7C 8C42A480 */  lw        $v0, -0x5b80($v0)
/* EC630 802C7C80 00031880 */  sll       $v1, $v1, 2
/* EC634 802C7C84 00621821 */  addu      $v1, $v1, $v0
/* EC638 802C7C88 8C630000 */  lw        $v1, ($v1)
/* EC63C 802C7C8C 080B1F37 */  j         .L802C7CDC
/* EC640 802C7C90 24020001 */   addiu    $v0, $zero, 1
.L802C7C94:
/* EC644 802C7C94 34427900 */  ori       $v0, $v0, 0x7900
/* EC648 802C7C98 0045102A */  slt       $v0, $v0, $a1
/* EC64C 802C7C9C 14400013 */  bnez      $v0, .L802C7CEC
/* EC650 802C7CA0 3C02FD9D */   lui      $v0, 0xfd9d
/* EC654 802C7CA4 3C02042C */  lui       $v0, 0x42c
/* EC658 802C7CA8 34421D80 */  ori       $v0, $v0, 0x1d80
/* EC65C 802C7CAC 00A22821 */  addu      $a1, $a1, $v0
/* EC660 802C7CB0 04A10002 */  bgez      $a1, .L802C7CBC
/* EC664 802C7CB4 00A0182D */   daddu    $v1, $a1, $zero
/* EC668 802C7CB8 24A3001F */  addiu     $v1, $a1, 0x1f
.L802C7CBC:
/* EC66C 802C7CBC 00033143 */  sra       $a2, $v1, 5
/* EC670 802C7CC0 00C0182D */  daddu     $v1, $a2, $zero
/* EC674 802C7CC4 00031140 */  sll       $v0, $v1, 5
/* EC678 802C7CC8 00A23023 */  subu      $a2, $a1, $v0
/* EC67C 802C7CCC 00031880 */  sll       $v1, $v1, 2
/* EC680 802C7CD0 00831821 */  addu      $v1, $a0, $v1
/* EC684 802C7CD4 24020001 */  addiu     $v0, $zero, 1
/* EC688 802C7CD8 8C6300C4 */  lw        $v1, 0xc4($v1)
.L802C7CDC:
/* EC68C 802C7CDC 00C21004 */  sllv      $v0, $v0, $a2
/* EC690 802C7CE0 00622824 */  and       $a1, $v1, $v0
/* EC694 802C7CE4 080B1F67 */  j         .L802C7D9C
/* EC698 802C7CE8 0005102B */   sltu     $v0, $zero, $a1
.L802C7CEC:
/* EC69C 802C7CEC 3442A600 */  ori       $v0, $v0, 0xa600
/* EC6A0 802C7CF0 0045102A */  slt       $v0, $v0, $a1
/* EC6A4 802C7CF4 14400010 */  bnez      $v0, .L802C7D38
/* EC6A8 802C7CF8 3C02FECE */   lui      $v0, 0xfece
/* EC6AC 802C7CFC 3C0202FA */  lui       $v0, 0x2fa
/* EC6B0 802C7D00 3442F080 */  ori       $v0, $v0, 0xf080
/* EC6B4 802C7D04 00A22821 */  addu      $a1, $a1, $v0
/* EC6B8 802C7D08 3C03EFE8 */  lui       $v1, 0xefe8
/* EC6BC 802C7D0C 3C04802E */  lui       $a0, 0x802e
/* EC6C0 802C7D10 8C84A484 */  lw        $a0, -0x5b7c($a0)
/* EC6C4 802C7D14 00051080 */  sll       $v0, $a1, 2
/* EC6C8 802C7D18 00441021 */  addu      $v0, $v0, $a0
/* EC6CC 802C7D1C 8C450000 */  lw        $a1, ($v0)
/* EC6D0 802C7D20 34632080 */  ori       $v1, $v1, 0x2080
/* EC6D4 802C7D24 0065182A */  slt       $v1, $v1, $a1
/* EC6D8 802C7D28 1060001B */  beqz      $v1, .L802C7D98
/* EC6DC 802C7D2C 3C02F2E3 */   lui      $v0, 0xf2e3
/* EC6E0 802C7D30 080B1F5E */  j         .L802C7D78
/* EC6E4 802C7D34 34421100 */   ori      $v0, $v0, 0x1100
.L802C7D38:
/* EC6E8 802C7D38 3442D300 */  ori       $v0, $v0, 0xd300
/* EC6EC 802C7D3C 0045102A */  slt       $v0, $v0, $a1
/* EC6F0 802C7D40 14400016 */  bnez      $v0, .L802C7D9C
/* EC6F4 802C7D44 00A0102D */   daddu    $v0, $a1, $zero
/* EC6F8 802C7D48 3C0201C9 */  lui       $v0, 0x1c9
/* EC6FC 802C7D4C 3442C380 */  ori       $v0, $v0, 0xc380
/* EC700 802C7D50 00A22821 */  addu      $a1, $a1, $v0
/* EC704 802C7D54 00051080 */  sll       $v0, $a1, 2
/* EC708 802C7D58 00821021 */  addu      $v0, $a0, $v0
/* EC70C 802C7D5C 8C450084 */  lw        $a1, 0x84($v0)
/* EC710 802C7D60 3C02EFE8 */  lui       $v0, 0xefe8
/* EC714 802C7D64 34422080 */  ori       $v0, $v0, 0x2080
/* EC718 802C7D68 0045102A */  slt       $v0, $v0, $a1
/* EC71C 802C7D6C 1040000A */  beqz      $v0, .L802C7D98
/* EC720 802C7D70 3C02F2E3 */   lui      $v0, 0xf2e3
/* EC724 802C7D74 34421100 */  ori       $v0, $v0, 0x1100
.L802C7D78:
/* EC728 802C7D78 0045102A */  slt       $v0, $v0, $a1
.L802C7D7C:
/* EC72C 802C7D7C 14400007 */  bnez      $v0, .L802C7D9C
/* EC730 802C7D80 00A0102D */   daddu    $v0, $a1, $zero
/* EC734 802C7D84 0C0B1248 */  jal       fixed_var_to_float
/* EC738 802C7D88 00A0202D */   daddu    $a0, $a1, $zero
/* EC73C 802C7D8C 4600008D */  trunc.w.s $f2, $f0
/* EC740 802C7D90 44051000 */  mfc1      $a1, $f2
/* EC744 802C7D94 00000000 */  nop       
.L802C7D98:
/* EC748 802C7D98 00A0102D */  daddu     $v0, $a1, $zero
.L802C7D9C:
/* EC74C 802C7D9C 8FBF0010 */  lw        $ra, 0x10($sp)
/* EC750 802C7DA0 03E00008 */  jr        $ra
/* EC754 802C7DA4 27BD0018 */   addiu    $sp, $sp, 0x18
