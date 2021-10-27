
      dimensionedScalar rhoInfValue
      (
          transportProperties.lookup("rhoInf")
      );

      dimensionedScalar invrhoInf("invrhoInf",(1.0/rhoInfValue));

      volScalarField rhoInf
      (
          IOobject
          (
              "rho",
              runTime.timeName(),
              mesh,
              IOobject::NO_READ,
              IOobject::NO_WRITE
          ),
          mesh,
          rhoInfValue
      );

      volScalarField mu
      (
          IOobject
          (
              "mu",
              runTime.timeName(),
              mesh,
              IOobject::NO_READ,
              IOobject::NO_WRITE
          ),
          laminarTransport.nu()*rhoInfValue
      );

// ----------------------------------------------------------------------------

      const word kinematicCloudName2
      (
          args.optionLookupOrDefault<word>("cloudName", "kinematicCloud2")
      );

      Info<< "Constructing kinematicCloud2 " << kinematicCloudName2 << endl;
      basicKinematicCollidingCloud kinematicCloud2
      (
          kinematicCloudName2,
          rhoInf,
          U,
          mu,
          g
      );

