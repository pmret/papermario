.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050FD0
/* 2C3D0 80050FD0 00041100 */  sll       $v0, $a0, 4
/* 2C3D4 80050FD4 00441023 */  subu      $v0, $v0, $a0
/* 2C3D8 80050FD8 000210C0 */  sll       $v0, $v0, 3
/* 2C3DC 80050FDC 00441021 */  addu      $v0, $v0, $a0
/* 2C3E0 80050FE0 00021080 */  sll       $v0, $v0, 2
/* 2C3E4 80050FE4 3C03800A */  lui       $v1, %hi(D_8009A628)
/* 2C3E8 80050FE8 8C63A628 */  lw        $v1, %lo(D_8009A628)($v1)
/* 2C3EC 80050FEC 24420024 */  addiu     $v0, $v0, 0x24
/* 2C3F0 80050FF0 00621821 */  addu      $v1, $v1, $v0
/* 2C3F4 80050FF4 8C620004 */  lw        $v0, 4($v1)
/* 2C3F8 80050FF8 10400013 */  beqz      $v0, .L80051048
/* 2C3FC 80050FFC 00000000 */   nop
/* 2C400 80051000 8C620008 */  lw        $v0, 8($v1)
/* 2C404 80051004 10400010 */  beqz      $v0, .L80051048
/* 2C408 80051008 00000000 */   nop
/* 2C40C 8005100C 1CC00003 */  bgtz      $a2, .L8005101C
/* 2C410 80051010 28C20080 */   slti     $v0, $a2, 0x80
/* 2C414 80051014 08014409 */  j         .L80051024
/* 2C418 80051018 24060001 */   addiu    $a2, $zero, 1
.L8005101C:
/* 2C41C 8005101C 50400001 */  beql      $v0, $zero, .L80051024
/* 2C420 80051020 2406007F */   addiu    $a2, $zero, 0x7f
.L80051024:
/* 2C424 80051024 10A00003 */  beqz      $a1, .L80051034
/* 2C428 80051028 240200FA */   addiu    $v0, $zero, 0xfa
/* 2C42C 8005102C 0801440E */  j         .L80051038
/* 2C430 80051030 A4650028 */   sh       $a1, 0x28($v1)
.L80051034:
/* 2C434 80051034 A4620028 */  sh        $v0, 0x28($v1)
.L80051038:
/* 2C438 80051038 240200FF */  addiu     $v0, $zero, 0xff
/* 2C43C 8005103C A062002A */  sb        $v0, 0x2a($v1)
/* 2C440 80051040 A066002B */  sb        $a2, 0x2b($v1)
/* 2C444 80051044 A0600026 */  sb        $zero, 0x26($v1)
.L80051048:
/* 2C448 80051048 03E00008 */  jr        $ra
/* 2C44C 8005104C 00000000 */   nop
