
.section .text8002AE40, "ax"

get_spirits_rescued:
/* 006240 8002AE40 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 006244 8002AE44 0000202D */  daddu $a0, $zero, $zero
/* 006248 8002AE48 3C05F5DE */  lui   $a1, 0xf5de
/* 00624C 8002AE4C 34A50180 */  ori   $a1, $a1, 0x180
/* 006250 8002AE50 AFBF0018 */  sw    $ra, 0x18($sp)
/* 006254 8002AE54 AFB10014 */  sw    $s1, 0x14($sp)
/* 006258 8002AE58 0C0B1EAF */  jal   get_variable
/* 00625C 8002AE5C AFB00010 */   sw    $s0, 0x10($sp)
/* 006260 8002AE60 24110007 */  addiu $s1, $zero, 7
/* 006264 8002AE64 0000202D */  daddu $a0, $zero, $zero
/* 006268 8002AE68 2405FFB3 */  addiu $a1, $zero, -0x4d
/* 00626C 8002AE6C 0C0B1EAF */  jal   get_variable
/* 006270 8002AE70 0040802D */   daddu $s0, $v0, $zero
/* 006274 8002AE74 0202102A */  slt   $v0, $s0, $v0
/* 006278 8002AE78 10400003 */  beqz  $v0, .L8002AE88
/* 00627C 8002AE7C 0000202D */   daddu $a0, $zero, $zero
/* 006280 8002AE80 0800ABCA */  j     func_8002AF28
/* 006284 8002AE84 0000882D */   daddu $s1, $zero, $zero

.L8002AE88:
/* 006288 8002AE88 0C0B1EAF */  jal   get_variable
/* 00628C 8002AE8C 2405FFC9 */   addiu $a1, $zero, -0x37
/* 006290 8002AE90 0202102A */  slt   $v0, $s0, $v0
/* 006294 8002AE94 10400003 */  beqz  $v0, .L8002AEA4
/* 006298 8002AE98 0000202D */   daddu $a0, $zero, $zero
/* 00629C 8002AE9C 0800ABCA */  j     func_8002AF28
/* 0062A0 8002AEA0 24110001 */   addiu $s1, $zero, 1

.L8002AEA4:
/* 0062A4 8002AEA4 0C0B1EAF */  jal   get_variable
/* 0062A8 8002AEA8 2405FFF1 */   addiu $a1, $zero, -0xf
/* 0062AC 8002AEAC 0202102A */  slt   $v0, $s0, $v0
/* 0062B0 8002AEB0 10400003 */  beqz  $v0, .L8002AEC0
/* 0062B4 8002AEB4 0000202D */   daddu $a0, $zero, $zero
/* 0062B8 8002AEB8 0800ABCA */  j     func_8002AF28
/* 0062BC 8002AEBC 24110002 */   addiu $s1, $zero, 2

.L8002AEC0:
/* 0062C0 8002AEC0 0C0B1EAF */  jal   get_variable
/* 0062C4 8002AEC4 24050005 */   addiu $a1, $zero, 5
/* 0062C8 8002AEC8 0202102A */  slt   $v0, $s0, $v0
/* 0062CC 8002AECC 10400003 */  beqz  $v0, .L8002AEDC
/* 0062D0 8002AED0 0000202D */   daddu $a0, $zero, $zero
/* 0062D4 8002AED4 0800ABCA */  j     func_8002AF28
/* 0062D8 8002AED8 24110003 */   addiu $s1, $zero, 3

.L8002AEDC:
/* 0062DC 8002AEDC 0C0B1EAF */  jal   get_variable
/* 0062E0 8002AEE0 24050025 */   addiu $a1, $zero, 0x25
/* 0062E4 8002AEE4 0202102A */  slt   $v0, $s0, $v0
/* 0062E8 8002AEE8 10400003 */  beqz  $v0, .L8002AEF8
/* 0062EC 8002AEEC 0000202D */   daddu $a0, $zero, $zero
/* 0062F0 8002AEF0 0800ABCA */  j     func_8002AF28
/* 0062F4 8002AEF4 24110004 */   addiu $s1, $zero, 4

.L8002AEF8:
/* 0062F8 8002AEF8 0C0B1EAF */  jal   get_variable
/* 0062FC 8002AEFC 24050039 */   addiu $a1, $zero, 0x39
/* 006300 8002AF00 0202102A */  slt   $v0, $s0, $v0
/* 006304 8002AF04 10400003 */  beqz  $v0, .L8002AF14
/* 006308 8002AF08 0000202D */   daddu $a0, $zero, $zero
/* 00630C 8002AF0C 0800ABCA */  j     func_8002AF28
/* 006310 8002AF10 24110005 */   addiu $s1, $zero, 5

.L8002AF14:
/* 006314 8002AF14 0C0B1EAF */  jal   get_variable
/* 006318 8002AF18 24050057 */   addiu $a1, $zero, 0x57
/* 00631C 8002AF1C 0202102A */  slt   $v0, $s0, $v0
/* 006320 8002AF20 54400001 */  bnezl $v0, .L8002AF28
/* 006324 8002AF24 24110006 */   addiu $s1, $zero, 6
func_8002AF28:
.L8002AF28:
/* 006328 8002AF28 0220102D */  daddu $v0, $s1, $zero
/* 00632C 8002AF2C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 006330 8002AF30 8FB10014 */  lw    $s1, 0x14($sp)
/* 006334 8002AF34 8FB00010 */  lw    $s0, 0x10($sp)
/* 006338 8002AF38 03E00008 */  jr    $ra
/* 00633C 8002AF3C 27BD0020 */   addiu $sp, $sp, 0x20

fio_calc_header_checksum:
/* 006340 8002AF40 0000282D */  daddu $a1, $zero, $zero
/* 006344 8002AF44 3C04800E */  lui   $a0, 0x800e
/* 006348 8002AF48 248495E8 */  addiu $a0, $a0, -0x6a18
/* 00634C 8002AF4C 00A0182D */  daddu $v1, $a1, $zero
.L8002AF50:
/* 006350 8002AF50 24630001 */  addiu $v1, $v1, 1
/* 006354 8002AF54 8C820000 */  lw    $v0, ($a0)
/* 006358 8002AF58 00A22821 */  addu  $a1, $a1, $v0
/* 00635C 8002AF5C 2C620020 */  sltiu $v0, $v1, 0x20
/* 006360 8002AF60 1440FFFB */  bnez  $v0, .L8002AF50
/* 006364 8002AF64 24840004 */   addiu $a0, $a0, 4
/* 006368 8002AF68 03E00008 */  jr    $ra
/* 00636C 8002AF6C 00A0102D */   daddu $v0, $a1, $zero

fio_validate_header_checksums:
/* 006370 8002AF70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006374 8002AF74 3C02800E */  lui   $v0, 0x800e
/* 006378 8002AF78 244295E8 */  addiu $v0, $v0, -0x6a18
/* 00637C 8002AF7C AFB00010 */  sw    $s0, 0x10($sp)
/* 006380 8002AF80 0040802D */  daddu $s0, $v0, $zero
/* 006384 8002AF84 3C058007 */  lui   $a1, 0x8007
/* 006388 8002AF88 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 00638C 8002AF8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 006390 8002AF90 0C01BB5C */  jal   strcmp
/* 006394 8002AF94 0200202D */   daddu $a0, $s0, $zero
/* 006398 8002AF98 1440000B */  bnez  $v0, .L8002AFC8
/* 00639C 8002AF9C 0000102D */   daddu $v0, $zero, $zero
/* 0063A0 8002AFA0 8E020034 */  lw    $v0, 0x34($s0)
/* 0063A4 8002AFA4 8E030030 */  lw    $v1, 0x30($s0)
/* 0063A8 8002AFA8 00021027 */  nor   $v0, $zero, $v0
/* 0063AC 8002AFAC 54620006 */  bnel  $v1, $v0, .L8002AFC8
/* 0063B0 8002AFB0 0000102D */   daddu $v0, $zero, $zero
/* 0063B4 8002AFB4 0C00ABD0 */  jal   fio_calc_header_checksum
/* 0063B8 8002AFB8 00000000 */   nop   
/* 0063BC 8002AFBC 8E030030 */  lw    $v1, 0x30($s0)
/* 0063C0 8002AFC0 00431026 */  xor   $v0, $v0, $v1
/* 0063C4 8002AFC4 2C420001 */  sltiu $v0, $v0, 1
.L8002AFC8:
/* 0063C8 8002AFC8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0063CC 8002AFCC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0063D0 8002AFD0 03E00008 */  jr    $ra
/* 0063D4 8002AFD4 27BD0018 */   addiu $sp, $sp, 0x18

fio_has_valid_backup:
/* 0063D8 8002AFD8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0063DC 8002AFDC 24040006 */  addiu $a0, $zero, 6
/* 0063E0 8002AFE0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0063E4 8002AFE4 3C10800E */  lui   $s0, 0x800e
/* 0063E8 8002AFE8 261095E8 */  addiu $s0, $s0, -0x6a18
/* 0063EC 8002AFEC 0200282D */  daddu $a1, $s0, $zero
/* 0063F0 8002AFF0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0063F4 8002AFF4 0C00AE1A */  jal   fio_read_flash
/* 0063F8 8002AFF8 24060080 */   addiu $a2, $zero, 0x80
/* 0063FC 8002AFFC 0C00ABDC */  jal   fio_validate_header_checksums
/* 006400 8002B000 00000000 */   nop   
/* 006404 8002B004 1440000D */  bnez  $v0, .L8002B03C
/* 006408 8002B008 24020001 */   addiu $v0, $zero, 1
/* 00640C 8002B00C 24040007 */  addiu $a0, $zero, 7
/* 006410 8002B010 0200282D */  daddu $a1, $s0, $zero
/* 006414 8002B014 0C00AE1A */  jal   fio_read_flash
/* 006418 8002B018 24060080 */   addiu $a2, $zero, 0x80
/* 00641C 8002B01C 0C00ABDC */  jal   fio_validate_header_checksums
/* 006420 8002B020 00000000 */   nop   
/* 006424 8002B024 14400005 */  bnez  $v0, .L8002B03C
/* 006428 8002B028 24020001 */   addiu $v0, $zero, 1
/* 00642C 8002B02C 0200202D */  daddu $a0, $s0, $zero
/* 006430 8002B030 0C01925C */  jal   bzero
/* 006434 8002B034 24050080 */   addiu $a1, $zero, 0x80
/* 006438 8002B038 0000102D */  daddu $v0, $zero, $zero
.L8002B03C:
/* 00643C 8002B03C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 006440 8002B040 8FB00010 */  lw    $s0, 0x10($sp)
/* 006444 8002B044 03E00008 */  jr    $ra
/* 006448 8002B048 27BD0018 */   addiu $sp, $sp, 0x18

fio_flush_backups:
/* 00644C 8002B04C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006450 8002B050 AFB00010 */  sw    $s0, 0x10($sp)
/* 006454 8002B054 3C10800E */  lui   $s0, 0x800e
/* 006458 8002B058 261095E8 */  addiu $s0, $s0, -0x6a18
/* 00645C 8002B05C 3C058007 */  lui   $a1, 0x8007
/* 006460 8002B060 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 006464 8002B064 AFBF0014 */  sw    $ra, 0x14($sp)
/* 006468 8002B068 0C01BB50 */  jal   strcpy
/* 00646C 8002B06C 0200202D */   daddu $a0, $s0, $zero
/* 006470 8002B070 2402FFFF */  addiu $v0, $zero, -1
/* 006474 8002B074 AE000030 */  sw    $zero, 0x30($s0)
/* 006478 8002B078 0C00ABD0 */  jal   fio_calc_header_checksum
/* 00647C 8002B07C AE020034 */   sw    $v0, 0x34($s0)
/* 006480 8002B080 24040006 */  addiu $a0, $zero, 6
/* 006484 8002B084 AE020030 */  sw    $v0, 0x30($s0)
/* 006488 8002B088 00021027 */  nor   $v0, $zero, $v0
/* 00648C 8002B08C 0C00AE87 */  jal   fio_erase_flash
/* 006490 8002B090 AE020034 */   sw    $v0, 0x34($s0)
/* 006494 8002B094 24040006 */  addiu $a0, $zero, 6
/* 006498 8002B098 0200282D */  daddu $a1, $s0, $zero
/* 00649C 8002B09C 0C00AE52 */  jal   fio_write_flash
/* 0064A0 8002B0A0 24060080 */   addiu $a2, $zero, 0x80
/* 0064A4 8002B0A4 0C00AE87 */  jal   fio_erase_flash
/* 0064A8 8002B0A8 24040007 */   addiu $a0, $zero, 7
/* 0064AC 8002B0AC 24040007 */  addiu $a0, $zero, 7
/* 0064B0 8002B0B0 0200282D */  daddu $a1, $s0, $zero
/* 0064B4 8002B0B4 0C00AE52 */  jal   fio_write_flash
/* 0064B8 8002B0B8 24060080 */   addiu $a2, $zero, 0x80
/* 0064BC 8002B0BC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0064C0 8002B0C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0064C4 8002B0C4 24020001 */  addiu $v0, $zero, 1
/* 0064C8 8002B0C8 03E00008 */  jr    $ra
/* 0064CC 8002B0CC 27BD0018 */   addiu $sp, $sp, 0x18

fio_calc_file_checksum:
/* 0064D0 8002B0D0 0000282D */  daddu $a1, $zero, $zero
/* 0064D4 8002B0D4 00A0182D */  daddu $v1, $a1, $zero
.L8002B0D8:
/* 0064D8 8002B0D8 24630001 */  addiu $v1, $v1, 1
/* 0064DC 8002B0DC 8C820000 */  lw    $v0, ($a0)
/* 0064E0 8002B0E0 00A22821 */  addu  $a1, $a1, $v0
/* 0064E4 8002B0E4 2C6204E0 */  sltiu $v0, $v1, 0x4e0
/* 0064E8 8002B0E8 1440FFFB */  bnez  $v0, .L8002B0D8
/* 0064EC 8002B0EC 24840004 */   addiu $a0, $a0, 4
/* 0064F0 8002B0F0 03E00008 */  jr    $ra
/* 0064F4 8002B0F4 00A0102D */   daddu $v0, $a1, $zero

fio_validate_file_checksum:
/* 0064F8 8002B0F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0064FC 8002B0FC AFB00010 */  sw    $s0, 0x10($sp)
/* 006500 8002B100 3C058007 */  lui   $a1, 0x8007
/* 006504 8002B104 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 006508 8002B108 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00650C 8002B10C 0C01BB5C */  jal   strcmp
/* 006510 8002B110 0080802D */   daddu $s0, $a0, $zero
/* 006514 8002B114 1440000B */  bnez  $v0, .L8002B144
/* 006518 8002B118 0000102D */   daddu $v0, $zero, $zero
/* 00651C 8002B11C 8E020034 */  lw    $v0, 0x34($s0)
/* 006520 8002B120 8E030030 */  lw    $v1, 0x30($s0)
/* 006524 8002B124 00021027 */  nor   $v0, $zero, $v0
/* 006528 8002B128 54620006 */  bnel  $v1, $v0, .L8002B144
/* 00652C 8002B12C 0000102D */   daddu $v0, $zero, $zero
/* 006530 8002B130 0C00AC34 */  jal   fio_calc_file_checksum
/* 006534 8002B134 0200202D */   daddu $a0, $s0, $zero
/* 006538 8002B138 8E030030 */  lw    $v1, 0x30($s0)
/* 00653C 8002B13C 00431026 */  xor   $v0, $v0, $v1
/* 006540 8002B140 2C420001 */  sltiu $v0, $v0, 1
.L8002B144:
/* 006544 8002B144 8FBF0014 */  lw    $ra, 0x14($sp)
/* 006548 8002B148 8FB00010 */  lw    $s0, 0x10($sp)
/* 00654C 8002B14C 03E00008 */  jr    $ra
/* 006550 8002B150 27BD0018 */   addiu $sp, $sp, 0x18

fio_fetch_saved_file_info:
/* 006554 8002B154 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 006558 8002B158 AFB20018 */  sw    $s2, 0x18($sp)
/* 00655C 8002B15C 3C12800A */  lui   $s2, 0x800a
/* 006560 8002B160 2652A6B0 */  addiu $s2, $s2, -0x5950
/* 006564 8002B164 AFB40020 */  sw    $s4, 0x20($sp)
/* 006568 8002B168 0240A02D */  daddu $s4, $s2, $zero
/* 00656C 8002B16C AFB00010 */  sw    $s0, 0x10($sp)
/* 006570 8002B170 0000802D */  daddu $s0, $zero, $zero
/* 006574 8002B174 2404FFFF */  addiu $a0, $zero, -1
/* 006578 8002B178 3C03800A */  lui   $v1, 0x800a
/* 00657C 8002B17C 2463BA30 */  addiu $v1, $v1, -0x45d0
/* 006580 8002B180 AFBF0024 */  sw    $ra, 0x24($sp)
/* 006584 8002B184 AFB3001C */  sw    $s3, 0x1c($sp)
/* 006588 8002B188 AFB10014 */  sw    $s1, 0x14($sp)
.L8002B18C:
/* 00658C 8002B18C AC640000 */  sw    $a0, ($v1)
/* 006590 8002B190 AC640004 */  sw    $a0, 4($v1)
/* 006594 8002B194 26100001 */  addiu $s0, $s0, 1
/* 006598 8002B198 2A020004 */  slti  $v0, $s0, 4
/* 00659C 8002B19C 1440FFFB */  bnez  $v0, .L8002B18C
/* 0065A0 8002B1A0 24630008 */   addiu $v1, $v1, 8
/* 0065A4 8002B1A4 0000802D */  daddu $s0, $zero, $zero
/* 0065A8 8002B1A8 3C13800A */  lui   $s3, 0x800a
/* 0065AC 8002B1AC 2673BA30 */  addiu $s3, $s3, -0x45d0
/* 0065B0 8002B1B0 3C11800A */  lui   $s1, 0x800a
/* 0065B4 8002B1B4 2631BA50 */  addiu $s1, $s1, -0x45b0
.L8002B1B8:
/* 0065B8 8002B1B8 0200202D */  daddu $a0, $s0, $zero
/* 0065BC 8002B1BC 0280282D */  daddu $a1, $s4, $zero
/* 0065C0 8002B1C0 0C00AE1A */  jal   fio_read_flash
/* 0065C4 8002B1C4 24061380 */   addiu $a2, $zero, 0x1380
/* 0065C8 8002B1C8 0C00AC3E */  jal   fio_validate_file_checksum
/* 0065CC 8002B1CC 0280202D */   daddu $a0, $s4, $zero
/* 0065D0 8002B1D0 50400014 */  beql  $v0, $zero, .L8002B224
/* 0065D4 8002B1D4 26100001 */   addiu $s0, $s0, 1
/* 0065D8 8002B1D8 8E420038 */  lw    $v0, 0x38($s2)
/* 0065DC 8002B1DC AE220000 */  sw    $v0, ($s1)
/* 0065E0 8002B1E0 8E42003C */  lw    $v0, 0x3c($s2)
/* 0065E4 8002B1E4 AE220004 */  sw    $v0, 4($s1)
/* 0065E8 8002B1E8 8E420038 */  lw    $v0, 0x38($s2)
/* 0065EC 8002B1EC 8E43003C */  lw    $v1, 0x3c($s2)
/* 0065F0 8002B1F0 000210C0 */  sll   $v0, $v0, 3
/* 0065F4 8002B1F4 00532021 */  addu  $a0, $v0, $s3
/* 0065F8 8002B1F8 8C820004 */  lw    $v0, 4($a0)
/* 0065FC 8002B1FC 0043102A */  slt   $v0, $v0, $v1
/* 006600 8002B200 50400008 */  beql  $v0, $zero, .L8002B224
/* 006604 8002B204 26100001 */   addiu $s0, $s0, 1
/* 006608 8002B208 AC900000 */  sw    $s0, ($a0)
/* 00660C 8002B20C 8E420038 */  lw    $v0, 0x38($s2)
/* 006610 8002B210 8E43003C */  lw    $v1, 0x3c($s2)
/* 006614 8002B214 000210C0 */  sll   $v0, $v0, 3
/* 006618 8002B218 00531021 */  addu  $v0, $v0, $s3
/* 00661C 8002B21C AC430004 */  sw    $v1, 4($v0)
/* 006620 8002B220 26100001 */  addiu $s0, $s0, 1
.L8002B224:
/* 006624 8002B224 2A020006 */  slti  $v0, $s0, 6
/* 006628 8002B228 1440FFE3 */  bnez  $v0, .L8002B1B8
/* 00662C 8002B22C 26310008 */   addiu $s1, $s1, 8
/* 006630 8002B230 3C067FFF */  lui   $a2, 0x7fff
/* 006634 8002B234 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 006638 8002B238 0000202D */  daddu $a0, $zero, $zero
/* 00663C 8002B23C 3C09800A */  lui   $t1, 0x800a
/* 006640 8002B240 2529BA30 */  addiu $t1, $t1, -0x45d0
/* 006644 8002B244 24080004 */  addiu $t0, $zero, 4
/* 006648 8002B248 3C07800A */  lui   $a3, 0x800a
/* 00664C 8002B24C 24E7BA80 */  addiu $a3, $a3, -0x4580
/* 006650 8002B250 3C05800A */  lui   $a1, 0x800a
/* 006654 8002B254 24A5BA50 */  addiu $a1, $a1, -0x45b0
.L8002B258:
/* 006658 8002B258 0000802D */  daddu $s0, $zero, $zero
/* 00665C 8002B25C 0120182D */  daddu $v1, $t1, $zero
.L8002B260:
/* 006660 8002B260 8C620000 */  lw    $v0, ($v1)
/* 006664 8002B264 10820005 */  beq   $a0, $v0, .L8002B27C
/* 006668 8002B268 00000000 */   nop   
/* 00666C 8002B26C 26100001 */  addiu $s0, $s0, 1
/* 006670 8002B270 2A020004 */  slti  $v0, $s0, 4
/* 006674 8002B274 1440FFFA */  bnez  $v0, .L8002B260
/* 006678 8002B278 24630008 */   addiu $v1, $v1, 8
.L8002B27C:
/* 00667C 8002B27C 56080008 */  bnel  $s0, $t0, .L8002B2A0
/* 006680 8002B280 24840001 */   addiu $a0, $a0, 1
/* 006684 8002B284 8CA30004 */  lw    $v1, 4($a1)
/* 006688 8002B288 0066102A */  slt   $v0, $v1, $a2
/* 00668C 8002B28C 50400004 */  beql  $v0, $zero, .L8002B2A0
/* 006690 8002B290 24840001 */   addiu $a0, $a0, 1
/* 006694 8002B294 0060302D */  daddu $a2, $v1, $zero
/* 006698 8002B298 ACE40000 */  sw    $a0, ($a3)
/* 00669C 8002B29C 24840001 */  addiu $a0, $a0, 1
.L8002B2A0:
/* 0066A0 8002B2A0 28820006 */  slti  $v0, $a0, 6
/* 0066A4 8002B2A4 1440FFEC */  bnez  $v0, .L8002B258
/* 0066A8 8002B2A8 24A50008 */   addiu $a1, $a1, 8
/* 0066AC 8002B2AC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0066B0 8002B2B0 8FB40020 */  lw    $s4, 0x20($sp)
/* 0066B4 8002B2B4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0066B8 8002B2B8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0066BC 8002B2BC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0066C0 8002B2C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0066C4 8002B2C4 24020001 */  addiu $v0, $zero, 1
/* 0066C8 8002B2C8 03E00008 */  jr    $ra
/* 0066CC 8002B2CC 27BD0028 */   addiu $sp, $sp, 0x28

fio_load_game:
/* 0066D0 8002B2D0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0066D4 8002B2D4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0066D8 8002B2D8 3C128007 */  lui   $s2, 0x8007
/* 0066DC 8002B2DC 2652419C */  addiu $s2, $s2, 0x419c
/* 0066E0 8002B2E0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0066E4 8002B2E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0066E8 8002B2E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0066EC 8002B2EC 8E420000 */  lw    $v0, ($s2)
/* 0066F0 8002B2F0 0080802D */  daddu $s0, $a0, $zero
/* 0066F4 8002B2F4 0C00AC55 */  jal   fio_fetch_saved_file_info
/* 0066F8 8002B2F8 A0500166 */   sb    $s0, 0x166($v0)
/* 0066FC 8002B2FC 3C11800E */  lui   $s1, 0x800e
/* 006700 8002B300 2631ACC0 */  addiu $s1, $s1, -0x5340
/* 006704 8002B304 0220282D */  daddu $a1, $s1, $zero
/* 006708 8002B308 001080C0 */  sll   $s0, $s0, 3
/* 00670C 8002B30C 3C04800A */  lui   $a0, 0x800a
/* 006710 8002B310 00902021 */  addu  $a0, $a0, $s0
/* 006714 8002B314 8C84BA30 */  lw    $a0, -0x45d0($a0)
/* 006718 8002B318 0C00AE1A */  jal   fio_read_flash
/* 00671C 8002B31C 24061380 */   addiu $a2, $zero, 0x1380
/* 006720 8002B320 3C058007 */  lui   $a1, 0x8007
/* 006724 8002B324 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 006728 8002B328 0C01BB5C */  jal   strcmp
/* 00672C 8002B32C 0220202D */   daddu $a0, $s1, $zero
/* 006730 8002B330 1440000A */  bnez  $v0, .L8002B35C
/* 006734 8002B334 0000102D */   daddu $v0, $zero, $zero
/* 006738 8002B338 8E430000 */  lw    $v1, ($s2)
/* 00673C 8002B33C 8E24003C */  lw    $a0, 0x3c($s1)
/* 006740 8002B340 8C620168 */  lw    $v0, 0x168($v1)
/* 006744 8002B344 0044102B */  sltu  $v0, $v0, $a0
/* 006748 8002B348 54400001 */  bnezl $v0, .L8002B350
/* 00674C 8002B34C AC640168 */   sw    $a0, 0x168($v1)
.L8002B350:
/* 006750 8002B350 0C00AD24 */  jal   fio_deserialize_state
/* 006754 8002B354 00000000 */   nop   
/* 006758 8002B358 24020001 */  addiu $v0, $zero, 1
.L8002B35C:
/* 00675C 8002B35C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 006760 8002B360 8FB20018 */  lw    $s2, 0x18($sp)
/* 006764 8002B364 8FB10014 */  lw    $s1, 0x14($sp)
/* 006768 8002B368 8FB00010 */  lw    $s0, 0x10($sp)
/* 00676C 8002B36C 03E00008 */  jr    $ra
/* 006770 8002B370 27BD0020 */   addiu $sp, $sp, 0x20

fio_save_game:
/* 006774 8002B374 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 006778 8002B378 AFB20018 */  sw    $s2, 0x18($sp)
/* 00677C 8002B37C 0080902D */  daddu $s2, $a0, $zero
/* 006780 8002B380 AFBF001C */  sw    $ra, 0x1c($sp)
/* 006784 8002B384 AFB10014 */  sw    $s1, 0x14($sp)
/* 006788 8002B388 0C00AC55 */  jal   fio_fetch_saved_file_info
/* 00678C 8002B38C AFB00010 */   sw    $s0, 0x10($sp)
/* 006790 8002B390 3C118007 */  lui   $s1, 0x8007
/* 006794 8002B394 2631419C */  addiu $s1, $s1, 0x419c
/* 006798 8002B398 8E220000 */  lw    $v0, ($s1)
/* 00679C 8002B39C 0C00AD8C */  jal   fio_serialize_state
/* 0067A0 8002B3A0 A0520166 */   sb    $s2, 0x166($v0)
/* 0067A4 8002B3A4 3C10800E */  lui   $s0, 0x800e
/* 0067A8 8002B3A8 2610ACC0 */  addiu $s0, $s0, -0x5340
/* 0067AC 8002B3AC 3C058007 */  lui   $a1, 0x8007
/* 0067B0 8002B3B0 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 0067B4 8002B3B4 0C01BB50 */  jal   strcpy
/* 0067B8 8002B3B8 0200202D */   daddu $a0, $s0, $zero
/* 0067BC 8002B3BC 8E230000 */  lw    $v1, ($s1)
/* 0067C0 8002B3C0 AE120038 */  sw    $s2, 0x38($s0)
/* 0067C4 8002B3C4 8C620168 */  lw    $v0, 0x168($v1)
/* 0067C8 8002B3C8 0200202D */  daddu $a0, $s0, $zero
/* 0067CC 8002B3CC 24420001 */  addiu $v0, $v0, 1
/* 0067D0 8002B3D0 AC620168 */  sw    $v0, 0x168($v1)
/* 0067D4 8002B3D4 AE02003C */  sw    $v0, 0x3c($s0)
/* 0067D8 8002B3D8 2402FFFF */  addiu $v0, $zero, -1
/* 0067DC 8002B3DC AE000030 */  sw    $zero, 0x30($s0)
/* 0067E0 8002B3E0 0C00AC34 */  jal   fio_calc_file_checksum
/* 0067E4 8002B3E4 AE020034 */   sw    $v0, 0x34($s0)
/* 0067E8 8002B3E8 3C11800A */  lui   $s1, 0x800a
/* 0067EC 8002B3EC 2631BA80 */  addiu $s1, $s1, -0x4580
/* 0067F0 8002B3F0 8E240000 */  lw    $a0, ($s1)
/* 0067F4 8002B3F4 AE020030 */  sw    $v0, 0x30($s0)
/* 0067F8 8002B3F8 00021027 */  nor   $v0, $zero, $v0
/* 0067FC 8002B3FC 0C00AE87 */  jal   fio_erase_flash
/* 006800 8002B400 AE020034 */   sw    $v0, 0x34($s0)
/* 006804 8002B404 0200282D */  daddu $a1, $s0, $zero
/* 006808 8002B408 8E240000 */  lw    $a0, ($s1)
/* 00680C 8002B40C 0C00AE52 */  jal   fio_write_flash
/* 006810 8002B410 24061380 */   addiu $a2, $zero, 0x1380
/* 006814 8002B414 8FBF001C */  lw    $ra, 0x1c($sp)
/* 006818 8002B418 8FB20018 */  lw    $s2, 0x18($sp)
/* 00681C 8002B41C 8FB10014 */  lw    $s1, 0x14($sp)
/* 006820 8002B420 8FB00010 */  lw    $s0, 0x10($sp)
/* 006824 8002B424 03E00008 */  jr    $ra
/* 006828 8002B428 27BD0020 */   addiu $sp, $sp, 0x20

fio_erase_game:
/* 00682C 8002B42C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 006830 8002B430 AFB20018 */  sw    $s2, 0x18($sp)
/* 006834 8002B434 0080902D */  daddu $s2, $a0, $zero
/* 006838 8002B438 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00683C 8002B43C AFB10014 */  sw    $s1, 0x14($sp)
/* 006840 8002B440 0C00AC55 */  jal   fio_fetch_saved_file_info
/* 006844 8002B444 AFB00010 */   sw    $s0, 0x10($sp)
/* 006848 8002B448 0000802D */  daddu $s0, $zero, $zero
/* 00684C 8002B44C 3C11800A */  lui   $s1, 0x800a
/* 006850 8002B450 2631BA50 */  addiu $s1, $s1, -0x45b0
.L8002B454:
/* 006854 8002B454 8E220000 */  lw    $v0, ($s1)
/* 006858 8002B458 54520004 */  bnel  $v0, $s2, .L8002B46C
/* 00685C 8002B45C 26100001 */   addiu $s0, $s0, 1
/* 006860 8002B460 0C00AE87 */  jal   fio_erase_flash
/* 006864 8002B464 0200202D */   daddu $a0, $s0, $zero
/* 006868 8002B468 26100001 */  addiu $s0, $s0, 1
.L8002B46C:
/* 00686C 8002B46C 2A020006 */  slti  $v0, $s0, 6
/* 006870 8002B470 1440FFF8 */  bnez  $v0, .L8002B454
/* 006874 8002B474 26310008 */   addiu $s1, $s1, 8
/* 006878 8002B478 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00687C 8002B47C 8FB20018 */  lw    $s2, 0x18($sp)
/* 006880 8002B480 8FB10014 */  lw    $s1, 0x14($sp)
/* 006884 8002B484 8FB00010 */  lw    $s0, 0x10($sp)
/* 006888 8002B488 03E00008 */  jr    $ra
/* 00688C 8002B48C 27BD0020 */   addiu $sp, $sp, 0x20

fio_deserialize_state:
/* 006890 8002B490 3C038011 */  lui   $v1, 0x8011
/* 006894 8002B494 2463F290 */  addiu $v1, $v1, -0xd70
/* 006898 8002B498 3C07800E */  lui   $a3, 0x800e
/* 00689C 8002B49C 24E7ACC0 */  addiu $a3, $a3, -0x5340
/* 0068A0 8002B4A0 24E20040 */  addiu $v0, $a3, 0x40
/* 0068A4 8002B4A4 24E40460 */  addiu $a0, $a3, 0x460
.L8002B4A8:
/* 0068A8 8002B4A8 8C490000 */  lw    $t1, ($v0)
/* 0068AC 8002B4AC 8C4A0004 */  lw    $t2, 4($v0)
/* 0068B0 8002B4B0 8C4B0008 */  lw    $t3, 8($v0)
/* 0068B4 8002B4B4 8C4C000C */  lw    $t4, 0xc($v0)
/* 0068B8 8002B4B8 AC690000 */  sw    $t1, ($v1)
/* 0068BC 8002B4BC AC6A0004 */  sw    $t2, 4($v1)
/* 0068C0 8002B4C0 AC6B0008 */  sw    $t3, 8($v1)
/* 0068C4 8002B4C4 AC6C000C */  sw    $t4, 0xc($v1)
/* 0068C8 8002B4C8 24420010 */  addiu $v0, $v0, 0x10
/* 0068CC 8002B4CC 1444FFF6 */  bne   $v0, $a0, .L8002B4A8
/* 0068D0 8002B4D0 24630010 */   addiu $v1, $v1, 0x10
/* 0068D4 8002B4D4 8C490000 */  lw    $t1, ($v0)
/* 0068D8 8002B4D8 8C4A0004 */  lw    $t2, 4($v0)
/* 0068DC 8002B4DC AC690000 */  sw    $t1, ($v1)
/* 0068E0 8002B4E0 AC6A0004 */  sw    $t2, 4($v1)
/* 0068E4 8002B4E4 3C038007 */  lui   $v1, 0x8007
/* 0068E8 8002B4E8 8C63419C */  lw    $v1, 0x419c($v1)
/* 0068EC 8002B4EC 94E20468 */  lhu   $v0, 0x468($a3)
/* 0068F0 8002B4F0 A4620086 */  sh    $v0, 0x86($v1)
/* 0068F4 8002B4F4 94E2046A */  lhu   $v0, 0x46a($a3)
/* 0068F8 8002B4F8 A462008C */  sh    $v0, 0x8c($v1)
/* 0068FC 8002B4FC 94E2046C */  lhu   $v0, 0x46c($a3)
/* 006900 8002B500 A462008E */  sh    $v0, 0x8e($v1)
/* 006904 8002B504 94E212E6 */  lhu   $v0, 0x12e6($a3)
/* 006908 8002B508 A4620160 */  sh    $v0, 0x160($v1)
/* 00690C 8002B50C 94E212E8 */  lhu   $v0, 0x12e8($a3)
/* 006910 8002B510 0000302D */  daddu $a2, $zero, $zero
/* 006914 8002B514 A4620162 */  sh    $v0, 0x162($v1)
/* 006918 8002B518 94E212EA */  lhu   $v0, 0x12ea($a3)
/* 00691C 8002B51C 3C08800B */  lui   $t0, 0x800b
/* 006920 8002B520 25080F10 */  addiu $t0, $t0, 0xf10
/* 006924 8002B524 A4620164 */  sh    $v0, 0x164($v1)
/* 006928 8002B528 0000282D */  daddu $a1, $zero, $zero
.L8002B52C:
/* 00692C 8002B52C 00062080 */  sll   $a0, $a2, 2
.L8002B530:
/* 006930 8002B530 00881821 */  addu  $v1, $a0, $t0
/* 006934 8002B534 00E41021 */  addu  $v0, $a3, $a0
/* 006938 8002B538 8C420470 */  lw    $v0, 0x470($v0)
/* 00693C 8002B53C 24A50001 */  addiu $a1, $a1, 1
/* 006940 8002B540 AC6200B0 */  sw    $v0, 0xb0($v1)
/* 006944 8002B544 28A2003C */  slti  $v0, $a1, 0x3c
/* 006948 8002B548 1440FFF9 */  bnez  $v0, .L8002B530
/* 00694C 8002B54C 24840030 */   addiu $a0, $a0, 0x30
/* 006950 8002B550 24C60001 */  addiu $a2, $a2, 1
/* 006954 8002B554 28C2000C */  slti  $v0, $a2, 0xc
/* 006958 8002B558 1440FFF4 */  bnez  $v0, .L8002B52C
/* 00695C 8002B55C 0000282D */   daddu $a1, $zero, $zero
/* 006960 8002B560 3C038007 */  lui   $v1, 0x8007
/* 006964 8002B564 2463419C */  addiu $v1, $v1, 0x419c
/* 006968 8002B568 8C620000 */  lw    $v0, ($v1)
/* 00696C 8002B56C A0400074 */  sb    $zero, 0x74($v0)
/* 006970 8002B570 8C620000 */  lw    $v0, ($v1)
/* 006974 8002B574 A0400076 */  sb    $zero, 0x76($v0)
/* 006978 8002B578 8C620000 */  lw    $v0, ($v1)
/* 00697C 8002B57C A0400077 */  sb    $zero, 0x77($v0)
/* 006980 8002B580 8C640000 */  lw    $a0, ($v1)
/* 006984 8002B584 24020001 */  addiu $v0, $zero, 1
/* 006988 8002B588 A082007A */  sb    $v0, 0x7a($a0)
/* 00698C 8002B58C 8C620000 */  lw    $v0, ($v1)
/* 006990 8002B590 90430166 */  lbu   $v1, 0x166($v0)
/* 006994 8002B594 00031040 */  sll   $v0, $v1, 1
/* 006998 8002B598 00431021 */  addu  $v0, $v0, $v1
/* 00699C 8002B59C 000210C0 */  sll   $v0, $v0, 3
/* 0069A0 8002B5A0 8CE912EC */  lw    $t1, 0x12ec($a3)
/* 0069A4 8002B5A4 8CEA12F0 */  lw    $t2, 0x12f0($a3)
/* 0069A8 8002B5A8 8CEB12F4 */  lw    $t3, 0x12f4($a3)
/* 0069AC 8002B5AC 8CEC12F8 */  lw    $t4, 0x12f8($a3)
/* 0069B0 8002B5B0 3C018007 */  lui   $at, 0x8007
/* 0069B4 8002B5B4 00220821 */  addu  $at, $at, $v0
/* 0069B8 8002B5B8 AC2979C4 */  sw    $t1, 0x79c4($at)
/* 0069BC 8002B5BC 3C018007 */  lui   $at, 0x8007
/* 0069C0 8002B5C0 00220821 */  addu  $at, $at, $v0
/* 0069C4 8002B5C4 AC2A79C8 */  sw    $t2, 0x79c8($at)
/* 0069C8 8002B5C8 3C018007 */  lui   $at, 0x8007
/* 0069CC 8002B5CC 00220821 */  addu  $at, $at, $v0
/* 0069D0 8002B5D0 AC2B79CC */  sw    $t3, 0x79cc($at)
/* 0069D4 8002B5D4 3C018007 */  lui   $at, 0x8007
/* 0069D8 8002B5D8 00220821 */  addu  $at, $at, $v0
/* 0069DC 8002B5DC AC2C79D0 */  sw    $t4, 0x79d0($at)
/* 0069E0 8002B5E0 8CE912FC */  lw    $t1, 0x12fc($a3)
/* 0069E4 8002B5E4 8CEA1300 */  lw    $t2, 0x1300($a3)
/* 0069E8 8002B5E8 3C018007 */  lui   $at, 0x8007
/* 0069EC 8002B5EC 00220821 */  addu  $at, $at, $v0
/* 0069F0 8002B5F0 AC2979D4 */  sw    $t1, 0x79d4($at)
/* 0069F4 8002B5F4 3C018007 */  lui   $at, 0x8007
/* 0069F8 8002B5F8 00220821 */  addu  $at, $at, $v0
/* 0069FC 8002B5FC AC2A79D8 */  sw    $t2, 0x79d8($at)
/* 006A00 8002B600 03E00008 */  jr    $ra
/* 006A04 8002B604 00000000 */   nop   

/* 006A08 8002B608 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006A0C 8002B60C 3C038007 */  lui   $v1, 0x8007
/* 006A10 8002B610 8C63419C */  lw    $v1, 0x419c($v1)
/* 006A14 8002B614 2402000A */  addiu $v0, $zero, 0xa
/* 006A18 8002B618 AFBF0010 */  sw    $ra, 0x10($sp)
/* 006A1C 8002B61C 0C00AD8C */  jal   fio_serialize_state
/* 006A20 8002B620 A462008E */   sh    $v0, 0x8e($v1)
/* 006A24 8002B624 8FBF0010 */  lw    $ra, 0x10($sp)
/* 006A28 8002B628 03E00008 */  jr    $ra
/* 006A2C 8002B62C 27BD0018 */   addiu $sp, $sp, 0x18

fio_serialize_state:
/* 006A30 8002B630 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 006A34 8002B634 AFB20018 */  sw    $s2, 0x18($sp)
/* 006A38 8002B638 3C12800E */  lui   $s2, 0x800e
/* 006A3C 8002B63C 2652ACC0 */  addiu $s2, $s2, -0x5340
/* 006A40 8002B640 26440040 */  addiu $a0, $s2, 0x40
/* 006A44 8002B644 3C028011 */  lui   $v0, 0x8011
/* 006A48 8002B648 2442F290 */  addiu $v0, $v0, -0xd70
/* 006A4C 8002B64C 24430420 */  addiu $v1, $v0, 0x420
/* 006A50 8002B650 AFBF001C */  sw    $ra, 0x1c($sp)
/* 006A54 8002B654 AFB10014 */  sw    $s1, 0x14($sp)
/* 006A58 8002B658 AFB00010 */  sw    $s0, 0x10($sp)
.L8002B65C:
/* 006A5C 8002B65C 8C480000 */  lw    $t0, ($v0)
/* 006A60 8002B660 8C490004 */  lw    $t1, 4($v0)
/* 006A64 8002B664 8C4A0008 */  lw    $t2, 8($v0)
/* 006A68 8002B668 8C4B000C */  lw    $t3, 0xc($v0)
/* 006A6C 8002B66C AC880000 */  sw    $t0, ($a0)
/* 006A70 8002B670 AC890004 */  sw    $t1, 4($a0)
/* 006A74 8002B674 AC8A0008 */  sw    $t2, 8($a0)
/* 006A78 8002B678 AC8B000C */  sw    $t3, 0xc($a0)
/* 006A7C 8002B67C 24420010 */  addiu $v0, $v0, 0x10
/* 006A80 8002B680 1443FFF6 */  bne   $v0, $v1, .L8002B65C
/* 006A84 8002B684 24840010 */   addiu $a0, $a0, 0x10
/* 006A88 8002B688 3C038007 */  lui   $v1, 0x8007
/* 006A8C 8002B68C 8C63419C */  lw    $v1, 0x419c($v1)
/* 006A90 8002B690 8C480000 */  lw    $t0, ($v0)
/* 006A94 8002B694 8C490004 */  lw    $t1, 4($v0)
/* 006A98 8002B698 AC880000 */  sw    $t0, ($a0)
/* 006A9C 8002B69C AC890004 */  sw    $t1, 4($a0)
/* 006AA0 8002B6A0 94620086 */  lhu   $v0, 0x86($v1)
/* 006AA4 8002B6A4 A6420468 */  sh    $v0, 0x468($s2)
/* 006AA8 8002B6A8 9462008C */  lhu   $v0, 0x8c($v1)
/* 006AAC 8002B6AC A642046A */  sh    $v0, 0x46a($s2)
/* 006AB0 8002B6B0 9462008E */  lhu   $v0, 0x8e($v1)
/* 006AB4 8002B6B4 A642046C */  sh    $v0, 0x46c($s2)
/* 006AB8 8002B6B8 94620160 */  lhu   $v0, 0x160($v1)
/* 006ABC 8002B6BC A64212E6 */  sh    $v0, 0x12e6($s2)
/* 006AC0 8002B6C0 94620162 */  lhu   $v0, 0x162($v1)
/* 006AC4 8002B6C4 0000302D */  daddu $a2, $zero, $zero
/* 006AC8 8002B6C8 A64212E8 */  sh    $v0, 0x12e8($s2)
/* 006ACC 8002B6CC 94620164 */  lhu   $v0, 0x164($v1)
/* 006AD0 8002B6D0 3C07800B */  lui   $a3, 0x800b
/* 006AD4 8002B6D4 24E70F10 */  addiu $a3, $a3, 0xf10
/* 006AD8 8002B6D8 A64212EA */  sh    $v0, 0x12ea($s2)
/* 006ADC 8002B6DC 0000282D */  daddu $a1, $zero, $zero
.L8002B6E0:
/* 006AE0 8002B6E0 00062080 */  sll   $a0, $a2, 2
.L8002B6E4:
/* 006AE4 8002B6E4 02441821 */  addu  $v1, $s2, $a0
/* 006AE8 8002B6E8 00871021 */  addu  $v0, $a0, $a3
/* 006AEC 8002B6EC 8C4200B0 */  lw    $v0, 0xb0($v0)
/* 006AF0 8002B6F0 24A50001 */  addiu $a1, $a1, 1
/* 006AF4 8002B6F4 AC620470 */  sw    $v0, 0x470($v1)
/* 006AF8 8002B6F8 28A2003C */  slti  $v0, $a1, 0x3c
/* 006AFC 8002B6FC 1440FFF9 */  bnez  $v0, .L8002B6E4
/* 006B00 8002B700 24840030 */   addiu $a0, $a0, 0x30
/* 006B04 8002B704 24C60001 */  addiu $a2, $a2, 1
/* 006B08 8002B708 28C2000C */  slti  $v0, $a2, 0xc
/* 006B0C 8002B70C 1440FFF4 */  bnez  $v0, .L8002B6E0
/* 006B10 8002B710 0000282D */   daddu $a1, $zero, $zero
/* 006B14 8002B714 3C108007 */  lui   $s0, 0x8007
/* 006B18 8002B718 2610419C */  addiu $s0, $s0, 0x419c
/* 006B1C 8002B71C 8E020000 */  lw    $v0, ($s0)
/* 006B20 8002B720 8E030000 */  lw    $v1, ($s0)
/* 006B24 8002B724 90420074 */  lbu   $v0, 0x74($v0)
/* 006B28 8002B728 A24212E0 */  sb    $v0, 0x12e0($s2)
/* 006B2C 8002B72C 90620076 */  lbu   $v0, 0x76($v1)
/* 006B30 8002B730 8E030000 */  lw    $v1, ($s0)
/* 006B34 8002B734 A24212E1 */  sb    $v0, 0x12e1($s2)
/* 006B38 8002B738 90620077 */  lbu   $v0, 0x77($v1)
/* 006B3C 8002B73C 8E030000 */  lw    $v1, ($s0)
/* 006B40 8002B740 A24212E2 */  sb    $v0, 0x12e2($s2)
/* 006B44 8002B744 9062007A */  lbu   $v0, 0x7a($v1)
/* 006B48 8002B748 8E030000 */  lw    $v1, ($s0)
/* 006B4C 8002B74C A24212E3 */  sb    $v0, 0x12e3($s2)
/* 006B50 8002B750 90630166 */  lbu   $v1, 0x166($v1)
/* 006B54 8002B754 3C118011 */  lui   $s1, 0x8011
/* 006B58 8002B758 2631F290 */  addiu $s1, $s1, -0xd70
/* 006B5C 8002B75C 00031040 */  sll   $v0, $v1, 1
/* 006B60 8002B760 00431021 */  addu  $v0, $v0, $v1
/* 006B64 8002B764 92230009 */  lbu   $v1, 9($s1)
/* 006B68 8002B768 000210C0 */  sll   $v0, $v0, 3
/* 006B6C 8002B76C 3C018007 */  lui   $at, 0x8007
/* 006B70 8002B770 00220821 */  addu  $at, $at, $v0
/* 006B74 8002B774 A02379CA */  sb    $v1, 0x79ca($at)
/* 006B78 8002B778 0C00AB90 */  jal   get_spirits_rescued
/* 006B7C 8002B77C 00000000 */   nop   
/* 006B80 8002B780 8E030000 */  lw    $v1, ($s0)
/* 006B84 8002B784 90640166 */  lbu   $a0, 0x166($v1)
/* 006B88 8002B788 00041840 */  sll   $v1, $a0, 1
/* 006B8C 8002B78C 00641821 */  addu  $v1, $v1, $a0
/* 006B90 8002B790 000318C0 */  sll   $v1, $v1, 3
/* 006B94 8002B794 3C018007 */  lui   $at, 0x8007
/* 006B98 8002B798 00230821 */  addu  $at, $at, $v1
/* 006B9C 8002B79C A02279C8 */  sb    $v0, 0x79c8($at)
/* 006BA0 8002B7A0 8E040000 */  lw    $a0, ($s0)
/* 006BA4 8002B7A4 90830166 */  lbu   $v1, 0x166($a0)
/* 006BA8 8002B7A8 00031040 */  sll   $v0, $v1, 1
/* 006BAC 8002B7AC 00431021 */  addu  $v0, $v0, $v1
/* 006BB0 8002B7B0 8E2302BC */  lw    $v1, 0x2bc($s1)
/* 006BB4 8002B7B4 000210C0 */  sll   $v0, $v0, 3
/* 006BB8 8002B7B8 3C018007 */  lui   $at, 0x8007
/* 006BBC 8002B7BC 00220821 */  addu  $at, $at, $v0
/* 006BC0 8002B7C0 AC2379C4 */  sw    $v1, 0x79c4($at)
/* 006BC4 8002B7C4 90830166 */  lbu   $v1, 0x166($a0)
/* 006BC8 8002B7C8 00031040 */  sll   $v0, $v1, 1
/* 006BCC 8002B7CC 00431021 */  addu  $v0, $v0, $v1
/* 006BD0 8002B7D0 000210C0 */  sll   $v0, $v0, 3
/* 006BD4 8002B7D4 3C088007 */  lui   $t0, 0x8007
/* 006BD8 8002B7D8 01024021 */  addu  $t0, $t0, $v0
/* 006BDC 8002B7DC 8D0879C4 */  lw    $t0, 0x79c4($t0)
/* 006BE0 8002B7E0 3C098007 */  lui   $t1, 0x8007
/* 006BE4 8002B7E4 01224821 */  addu  $t1, $t1, $v0
/* 006BE8 8002B7E8 8D2979C8 */  lw    $t1, 0x79c8($t1)
/* 006BEC 8002B7EC 3C0A8007 */  lui   $t2, 0x8007
/* 006BF0 8002B7F0 01425021 */  addu  $t2, $t2, $v0
/* 006BF4 8002B7F4 8D4A79CC */  lw    $t2, 0x79cc($t2)
/* 006BF8 8002B7F8 3C0B8007 */  lui   $t3, 0x8007
/* 006BFC 8002B7FC 01625821 */  addu  $t3, $t3, $v0
/* 006C00 8002B800 8D6B79D0 */  lw    $t3, 0x79d0($t3)
/* 006C04 8002B804 AE4812EC */  sw    $t0, 0x12ec($s2)
/* 006C08 8002B808 AE4912F0 */  sw    $t1, 0x12f0($s2)
/* 006C0C 8002B80C AE4A12F4 */  sw    $t2, 0x12f4($s2)
/* 006C10 8002B810 AE4B12F8 */  sw    $t3, 0x12f8($s2)
/* 006C14 8002B814 3C088007 */  lui   $t0, 0x8007
/* 006C18 8002B818 01024021 */  addu  $t0, $t0, $v0
/* 006C1C 8002B81C 8D0879D4 */  lw    $t0, 0x79d4($t0)
/* 006C20 8002B820 3C098007 */  lui   $t1, 0x8007
/* 006C24 8002B824 01224821 */  addu  $t1, $t1, $v0
/* 006C28 8002B828 8D2979D8 */  lw    $t1, 0x79d8($t1)
/* 006C2C 8002B82C AE4812FC */  sw    $t0, 0x12fc($s2)
/* 006C30 8002B830 AE491300 */  sw    $t1, 0x1300($s2)
/* 006C34 8002B834 8FBF001C */  lw    $ra, 0x1c($sp)
/* 006C38 8002B838 8FB20018 */  lw    $s2, 0x18($sp)
/* 006C3C 8002B83C 8FB10014 */  lw    $s1, 0x14($sp)
/* 006C40 8002B840 8FB00010 */  lw    $s0, 0x10($sp)
/* 006C44 8002B844 03E00008 */  jr    $ra
/* 006C48 8002B848 27BD0020 */   addiu $sp, $sp, 0x20

fio_init_flash:
/* 006C4C 8002B84C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006C50 8002B850 AFBF0010 */  sw    $ra, 0x10($sp)
/* 006C54 8002B854 0C01BBDA */  jal   osFlashInit
/* 006C58 8002B858 00000000 */   nop   
/* 006C5C 8002B85C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 006C60 8002B860 03E00008 */  jr    $ra
/* 006C64 8002B864 27BD0018 */   addiu $sp, $sp, 0x18

fio_read_flash:
/* 006C68 8002B868 27BDFF90 */  addiu $sp, $sp, -0x70
/* 006C6C 8002B86C AFB40060 */  sw    $s4, 0x60($sp)
/* 006C70 8002B870 0080A02D */  daddu $s4, $a0, $zero
/* 006C74 8002B874 AFB10054 */  sw    $s1, 0x54($sp)
/* 006C78 8002B878 00C0882D */  daddu $s1, $a2, $zero
/* 006C7C 8002B87C AFB20058 */  sw    $s2, 0x58($sp)
/* 006C80 8002B880 00A0902D */  daddu $s2, $a1, $zero
/* 006C84 8002B884 0240202D */  daddu $a0, $s2, $zero
/* 006C88 8002B888 0220282D */  daddu $a1, $s1, $zero
/* 006C8C 8002B88C AFBF006C */  sw    $ra, 0x6c($sp)
/* 006C90 8002B890 AFB60068 */  sw    $s6, 0x68($sp)
/* 006C94 8002B894 AFB50064 */  sw    $s5, 0x64($sp)
/* 006C98 8002B898 AFB3005C */  sw    $s3, 0x5c($sp)
/* 006C9C 8002B89C 0C0185C8 */  jal   osInvalDCache
/* 006CA0 8002B8A0 AFB00050 */   sw    $s0, 0x50($sp)
/* 006CA4 8002B8A4 27B00030 */  addiu $s0, $sp, 0x30
/* 006CA8 8002B8A8 0200202D */  daddu $a0, $s0, $zero
/* 006CAC 8002B8AC 27A50048 */  addiu $a1, $sp, 0x48
/* 006CB0 8002B8B0 0C019560 */  jal   osCreateMesgQueue
/* 006CB4 8002B8B4 24060001 */   addiu $a2, $zero, 1
/* 006CB8 8002B8B8 12200018 */  beqz  $s1, .L8002B91C
/* 006CBC 8002B8BC 0000982D */   daddu $s3, $zero, $zero
/* 006CC0 8002B8C0 0014A9C0 */  sll   $s5, $s4, 7
/* 006CC4 8002B8C4 24160001 */  addiu $s6, $zero, 1
/* 006CC8 8002B8C8 0200A02D */  daddu $s4, $s0, $zero
.L8002B8CC:
/* 006CCC 8002B8CC 2E220081 */  sltiu $v0, $s1, 0x81
/* 006CD0 8002B8D0 14400002 */  bnez  $v0, .L8002B8DC
/* 006CD4 8002B8D4 0220802D */   daddu $s0, $s1, $zero
/* 006CD8 8002B8D8 24100080 */  addiu $s0, $zero, 0x80
.L8002B8DC:
/* 006CDC 8002B8DC 27A40018 */  addiu $a0, $sp, 0x18
/* 006CE0 8002B8E0 0000282D */  daddu $a1, $zero, $zero
/* 006CE4 8002B8E4 3266FFFF */  andi  $a2, $s3, 0xffff
/* 006CE8 8002B8E8 02A63021 */  addu  $a2, $s5, $a2
/* 006CEC 8002B8EC 0240382D */  daddu $a3, $s2, $zero
/* 006CF0 8002B8F0 AFB60010 */  sw    $s6, 0x10($sp)
/* 006CF4 8002B8F4 0C01BDD7 */  jal   osFlashReadArray
/* 006CF8 8002B8F8 AFB40014 */   sw    $s4, 0x14($sp)
/* 006CFC 8002B8FC 0280202D */  daddu $a0, $s4, $zero
/* 006D00 8002B900 0000282D */  daddu $a1, $zero, $zero
/* 006D04 8002B904 0C0195BC */  jal   osRecvMesg
/* 006D08 8002B908 24060001 */   addiu $a2, $zero, 1
/* 006D0C 8002B90C 26730001 */  addiu $s3, $s3, 1
/* 006D10 8002B910 02308823 */  subu  $s1, $s1, $s0
/* 006D14 8002B914 1620FFED */  bnez  $s1, .L8002B8CC
/* 006D18 8002B918 02509021 */   addu  $s2, $s2, $s0
.L8002B91C:
/* 006D1C 8002B91C 8FBF006C */  lw    $ra, 0x6c($sp)
/* 006D20 8002B920 8FB60068 */  lw    $s6, 0x68($sp)
/* 006D24 8002B924 8FB50064 */  lw    $s5, 0x64($sp)
/* 006D28 8002B928 8FB40060 */  lw    $s4, 0x60($sp)
/* 006D2C 8002B92C 8FB3005C */  lw    $s3, 0x5c($sp)
/* 006D30 8002B930 8FB20058 */  lw    $s2, 0x58($sp)
/* 006D34 8002B934 8FB10054 */  lw    $s1, 0x54($sp)
/* 006D38 8002B938 8FB00050 */  lw    $s0, 0x50($sp)
/* 006D3C 8002B93C 24020001 */  addiu $v0, $zero, 1
/* 006D40 8002B940 03E00008 */  jr    $ra
/* 006D44 8002B944 27BD0070 */   addiu $sp, $sp, 0x70

fio_write_flash:
/* 006D48 8002B948 27BDFF98 */  addiu $sp, $sp, -0x68
/* 006D4C 8002B94C AFB5005C */  sw    $s5, 0x5c($sp)
/* 006D50 8002B950 0080A82D */  daddu $s5, $a0, $zero
/* 006D54 8002B954 AFB20050 */  sw    $s2, 0x50($sp)
/* 006D58 8002B958 00A0902D */  daddu $s2, $a1, $zero
/* 006D5C 8002B95C AFB1004C */  sw    $s1, 0x4c($sp)
/* 006D60 8002B960 00C0882D */  daddu $s1, $a2, $zero
/* 006D64 8002B964 0240202D */  daddu $a0, $s2, $zero
/* 006D68 8002B968 0220282D */  daddu $a1, $s1, $zero
/* 006D6C 8002B96C AFBF0060 */  sw    $ra, 0x60($sp)
/* 006D70 8002B970 AFB40058 */  sw    $s4, 0x58($sp)
/* 006D74 8002B974 AFB30054 */  sw    $s3, 0x54($sp)
/* 006D78 8002B978 0C018614 */  jal   osWritebackDCache
/* 006D7C 8002B97C AFB00048 */   sw    $s0, 0x48($sp)
/* 006D80 8002B980 27B00028 */  addiu $s0, $sp, 0x28
/* 006D84 8002B984 0200202D */  daddu $a0, $s0, $zero
/* 006D88 8002B988 27A50040 */  addiu $a1, $sp, 0x40
/* 006D8C 8002B98C 0C019560 */  jal   osCreateMesgQueue
/* 006D90 8002B990 24060001 */   addiu $a2, $zero, 1
/* 006D94 8002B994 12200017 */  beqz  $s1, .L8002B9F4
/* 006D98 8002B998 0000982D */   daddu $s3, $zero, $zero
/* 006D9C 8002B99C 0200A02D */  daddu $s4, $s0, $zero
/* 006DA0 8002B9A0 0015A9C0 */  sll   $s5, $s5, 7
.L8002B9A4:
/* 006DA4 8002B9A4 2E220081 */  sltiu $v0, $s1, 0x81
/* 006DA8 8002B9A8 14400002 */  bnez  $v0, .L8002B9B4
/* 006DAC 8002B9AC 0220802D */   daddu $s0, $s1, $zero
/* 006DB0 8002B9B0 24100080 */  addiu $s0, $zero, 0x80
.L8002B9B4:
/* 006DB4 8002B9B4 27A40010 */  addiu $a0, $sp, 0x10
/* 006DB8 8002B9B8 0000282D */  daddu $a1, $zero, $zero
/* 006DBC 8002B9BC 0240302D */  daddu $a2, $s2, $zero
/* 006DC0 8002B9C0 0C01BD54 */  jal   osFlashWriteBuffer
/* 006DC4 8002B9C4 0280382D */   daddu $a3, $s4, $zero
/* 006DC8 8002B9C8 3264FFFF */  andi  $a0, $s3, 0xffff
/* 006DCC 8002B9CC 0C01BD87 */  jal   osFlashWriteArray
/* 006DD0 8002B9D0 02A42021 */   addu  $a0, $s5, $a0
/* 006DD4 8002B9D4 0280202D */  daddu $a0, $s4, $zero
/* 006DD8 8002B9D8 0000282D */  daddu $a1, $zero, $zero
/* 006DDC 8002B9DC 0C0195BC */  jal   osRecvMesg
/* 006DE0 8002B9E0 24060001 */   addiu $a2, $zero, 1
/* 006DE4 8002B9E4 26730001 */  addiu $s3, $s3, 1
/* 006DE8 8002B9E8 02308823 */  subu  $s1, $s1, $s0
/* 006DEC 8002B9EC 1620FFED */  bnez  $s1, .L8002B9A4
/* 006DF0 8002B9F0 02509021 */   addu  $s2, $s2, $s0
.L8002B9F4:
/* 006DF4 8002B9F4 8FBF0060 */  lw    $ra, 0x60($sp)
/* 006DF8 8002B9F8 8FB5005C */  lw    $s5, 0x5c($sp)
/* 006DFC 8002B9FC 8FB40058 */  lw    $s4, 0x58($sp)
/* 006E00 8002BA00 8FB30054 */  lw    $s3, 0x54($sp)
/* 006E04 8002BA04 8FB20050 */  lw    $s2, 0x50($sp)
/* 006E08 8002BA08 8FB1004C */  lw    $s1, 0x4c($sp)
/* 006E0C 8002BA0C 8FB00048 */  lw    $s0, 0x48($sp)
/* 006E10 8002BA10 24020001 */  addiu $v0, $zero, 1
/* 006E14 8002BA14 03E00008 */  jr    $ra
/* 006E18 8002BA18 27BD0068 */   addiu $sp, $sp, 0x68

fio_erase_flash:
/* 006E1C 8002BA1C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006E20 8002BA20 AFBF0010 */  sw    $ra, 0x10($sp)
/* 006E24 8002BA24 0C01BD09 */  jal   osFlashSectorErase
/* 006E28 8002BA28 000421C0 */   sll   $a0, $a0, 7
/* 006E2C 8002BA2C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 006E30 8002BA30 03E00008 */  jr    $ra
/* 006E34 8002BA34 27BD0018 */   addiu $sp, $sp, 0x18

/* 006E38 8002BA38 00000000 */  nop   
/* 006E3C 8002BA3C 00000000 */  nop   
