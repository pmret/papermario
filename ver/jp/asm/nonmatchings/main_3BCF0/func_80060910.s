.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060910
/* 3BD10 80060910 400C6000 */  mfc0      $t4, $12
/* 3BD14 80060914 3182FF01 */  andi      $v0, $t4, 0xff01
/* 3BD18 80060918 3C088009 */  lui       $t0, %hi(D_80095890)
/* 3BD1C 8006091C 25085890 */  addiu     $t0, $t0, %lo(D_80095890)
/* 3BD20 80060920 8D0B0000 */  lw        $t3, ($t0)
/* 3BD24 80060924 2401FFFF */  addiu     $at, $zero, -1
/* 3BD28 80060928 01614026 */  xor       $t0, $t3, $at
/* 3BD2C 8006092C 3108FF00 */  andi      $t0, $t0, 0xff00
/* 3BD30 80060930 00481025 */  or        $v0, $v0, $t0
/* 3BD34 80060934 3C0AA430 */  lui       $t2, %hi(D_A430000C)
/* 3BD38 80060938 8D4A000C */  lw        $t2, %lo(D_A430000C)($t2)
/* 3BD3C 8006093C 11400005 */  beqz      $t2, .L80060954
/* 3BD40 80060940 000B4C02 */   srl      $t1, $t3, 0x10
/* 3BD44 80060944 2401FFFF */  addiu     $at, $zero, -1
/* 3BD48 80060948 01214826 */  xor       $t1, $t1, $at
/* 3BD4C 8006094C 3129003F */  andi      $t1, $t1, 0x3f
/* 3BD50 80060950 01495025 */  or        $t2, $t2, $t1
.L80060954:
/* 3BD54 80060954 000A5400 */  sll       $t2, $t2, 0x10
/* 3BD58 80060958 004A1025 */  or        $v0, $v0, $t2
/* 3BD5C 8006095C 3C01003F */  lui       $at, 0x3f
/* 3BD60 80060960 00814024 */  and       $t0, $a0, $at
/* 3BD64 80060964 010B4024 */  and       $t0, $t0, $t3
/* 3BD68 80060968 000843C2 */  srl       $t0, $t0, 0xf
/* 3BD6C 8006096C 3C0A800A */  lui       $t2, %hi(D_80099A80)
/* 3BD70 80060970 01485021 */  addu      $t2, $t2, $t0
/* 3BD74 80060974 954A9A80 */  lhu       $t2, %lo(D_80099A80)($t2)
/* 3BD78 80060978 3C01A430 */  lui       $at, %hi(D_A430000C)
/* 3BD7C 8006097C AC2A000C */  sw        $t2, %lo(D_A430000C)($at)
/* 3BD80 80060980 3088FF01 */  andi      $t0, $a0, 0xff01
/* 3BD84 80060984 3169FF00 */  andi      $t1, $t3, 0xff00
/* 3BD88 80060988 01094024 */  and       $t0, $t0, $t1
/* 3BD8C 8006098C 3C01FFFF */  lui       $at, 0xffff
/* 3BD90 80060990 342100FF */  ori       $at, $at, 0xff
/* 3BD94 80060994 01816024 */  and       $t4, $t4, $at
/* 3BD98 80060998 01886025 */  or        $t4, $t4, $t0
/* 3BD9C 8006099C 408C6000 */  mtc0      $t4, $12
/* 3BDA0 800609A0 00000000 */  nop
/* 3BDA4 800609A4 00000000 */  nop
/* 3BDA8 800609A8 03E00008 */  jr        $ra
/* 3BDAC 800609AC 00000000 */   nop
