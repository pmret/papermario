.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_fetch_saved_file_info
/* 6554 8002B154 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6558 8002B158 AFB20018 */  sw        $s2, 0x18($sp)
/* 655C 8002B15C 3C12800A */  lui       $s2, %hi(D_8009A6B0)
/* 6560 8002B160 2652A6B0 */  addiu     $s2, $s2, %lo(D_8009A6B0)
/* 6564 8002B164 AFB40020 */  sw        $s4, 0x20($sp)
/* 6568 8002B168 0240A02D */  daddu     $s4, $s2, $zero
/* 656C 8002B16C AFB00010 */  sw        $s0, 0x10($sp)
/* 6570 8002B170 0000802D */  daddu     $s0, $zero, $zero
/* 6574 8002B174 2404FFFF */  addiu     $a0, $zero, -1
/* 6578 8002B178 3C03800A */  lui       $v1, %hi(D_8009BA30)
/* 657C 8002B17C 2463BA30 */  addiu     $v1, $v1, %lo(D_8009BA30)
/* 6580 8002B180 AFBF0024 */  sw        $ra, 0x24($sp)
/* 6584 8002B184 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6588 8002B188 AFB10014 */  sw        $s1, 0x14($sp)
.L8002B18C:
/* 658C 8002B18C AC640000 */  sw        $a0, ($v1)
/* 6590 8002B190 AC640004 */  sw        $a0, 4($v1)
/* 6594 8002B194 26100001 */  addiu     $s0, $s0, 1
/* 6598 8002B198 2A020004 */  slti      $v0, $s0, 4
/* 659C 8002B19C 1440FFFB */  bnez      $v0, .L8002B18C
/* 65A0 8002B1A0 24630008 */   addiu    $v1, $v1, 8
/* 65A4 8002B1A4 0000802D */  daddu     $s0, $zero, $zero
/* 65A8 8002B1A8 3C13800A */  lui       $s3, %hi(D_8009BA30)
/* 65AC 8002B1AC 2673BA30 */  addiu     $s3, $s3, %lo(D_8009BA30)
/* 65B0 8002B1B0 3C11800A */  lui       $s1, %hi(D_8009BA50)
/* 65B4 8002B1B4 2631BA50 */  addiu     $s1, $s1, %lo(D_8009BA50)
.L8002B1B8:
/* 65B8 8002B1B8 0200202D */  daddu     $a0, $s0, $zero
/* 65BC 8002B1BC 0280282D */  daddu     $a1, $s4, $zero
/* 65C0 8002B1C0 0C00AE1A */  jal       fio_read_flash
/* 65C4 8002B1C4 24061380 */   addiu    $a2, $zero, 0x1380
/* 65C8 8002B1C8 0C00AC3E */  jal       fio_validate_file_checksum
/* 65CC 8002B1CC 0280202D */   daddu    $a0, $s4, $zero
/* 65D0 8002B1D0 50400014 */  beql      $v0, $zero, .L8002B224
/* 65D4 8002B1D4 26100001 */   addiu    $s0, $s0, 1
/* 65D8 8002B1D8 8E420038 */  lw        $v0, 0x38($s2)
/* 65DC 8002B1DC AE220000 */  sw        $v0, ($s1)
/* 65E0 8002B1E0 8E42003C */  lw        $v0, 0x3c($s2)
/* 65E4 8002B1E4 AE220004 */  sw        $v0, 4($s1)
/* 65E8 8002B1E8 8E420038 */  lw        $v0, 0x38($s2)
/* 65EC 8002B1EC 8E43003C */  lw        $v1, 0x3c($s2)
/* 65F0 8002B1F0 000210C0 */  sll       $v0, $v0, 3
/* 65F4 8002B1F4 00532021 */  addu      $a0, $v0, $s3
/* 65F8 8002B1F8 8C820004 */  lw        $v0, 4($a0)
/* 65FC 8002B1FC 0043102A */  slt       $v0, $v0, $v1
/* 6600 8002B200 50400008 */  beql      $v0, $zero, .L8002B224
/* 6604 8002B204 26100001 */   addiu    $s0, $s0, 1
/* 6608 8002B208 AC900000 */  sw        $s0, ($a0)
/* 660C 8002B20C 8E420038 */  lw        $v0, 0x38($s2)
/* 6610 8002B210 8E43003C */  lw        $v1, 0x3c($s2)
/* 6614 8002B214 000210C0 */  sll       $v0, $v0, 3
/* 6618 8002B218 00531021 */  addu      $v0, $v0, $s3
/* 661C 8002B21C AC430004 */  sw        $v1, 4($v0)
/* 6620 8002B220 26100001 */  addiu     $s0, $s0, 1
.L8002B224:
/* 6624 8002B224 2A020006 */  slti      $v0, $s0, 6
/* 6628 8002B228 1440FFE3 */  bnez      $v0, .L8002B1B8
/* 662C 8002B22C 26310008 */   addiu    $s1, $s1, 8
/* 6630 8002B230 3C067FFF */  lui       $a2, 0x7fff
/* 6634 8002B234 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 6638 8002B238 0000202D */  daddu     $a0, $zero, $zero
/* 663C 8002B23C 3C09800A */  lui       $t1, %hi(D_8009BA30)
/* 6640 8002B240 2529BA30 */  addiu     $t1, $t1, %lo(D_8009BA30)
/* 6644 8002B244 24080004 */  addiu     $t0, $zero, 4
/* 6648 8002B248 3C07800A */  lui       $a3, %hi(D_8009BA80)
/* 664C 8002B24C 24E7BA80 */  addiu     $a3, $a3, %lo(D_8009BA80)
/* 6650 8002B250 3C05800A */  lui       $a1, %hi(D_8009BA50)
/* 6654 8002B254 24A5BA50 */  addiu     $a1, $a1, %lo(D_8009BA50)
.L8002B258:
/* 6658 8002B258 0000802D */  daddu     $s0, $zero, $zero
/* 665C 8002B25C 0120182D */  daddu     $v1, $t1, $zero
.L8002B260:
/* 6660 8002B260 8C620000 */  lw        $v0, ($v1)
/* 6664 8002B264 10820005 */  beq       $a0, $v0, .L8002B27C
/* 6668 8002B268 00000000 */   nop      
/* 666C 8002B26C 26100001 */  addiu     $s0, $s0, 1
/* 6670 8002B270 2A020004 */  slti      $v0, $s0, 4
/* 6674 8002B274 1440FFFA */  bnez      $v0, .L8002B260
/* 6678 8002B278 24630008 */   addiu    $v1, $v1, 8
.L8002B27C:
/* 667C 8002B27C 56080008 */  bnel      $s0, $t0, .L8002B2A0
/* 6680 8002B280 24840001 */   addiu    $a0, $a0, 1
/* 6684 8002B284 8CA30004 */  lw        $v1, 4($a1)
/* 6688 8002B288 0066102A */  slt       $v0, $v1, $a2
/* 668C 8002B28C 50400004 */  beql      $v0, $zero, .L8002B2A0
/* 6690 8002B290 24840001 */   addiu    $a0, $a0, 1
/* 6694 8002B294 0060302D */  daddu     $a2, $v1, $zero
/* 6698 8002B298 ACE40000 */  sw        $a0, ($a3)
/* 669C 8002B29C 24840001 */  addiu     $a0, $a0, 1
.L8002B2A0:
/* 66A0 8002B2A0 28820006 */  slti      $v0, $a0, 6
/* 66A4 8002B2A4 1440FFEC */  bnez      $v0, .L8002B258
/* 66A8 8002B2A8 24A50008 */   addiu    $a1, $a1, 8
/* 66AC 8002B2AC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 66B0 8002B2B0 8FB40020 */  lw        $s4, 0x20($sp)
/* 66B4 8002B2B4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 66B8 8002B2B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 66BC 8002B2BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 66C0 8002B2C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 66C4 8002B2C4 24020001 */  addiu     $v0, $zero, 1
/* 66C8 8002B2C8 03E00008 */  jr        $ra
/* 66CC 8002B2CC 27BD0028 */   addiu    $sp, $sp, 0x28
